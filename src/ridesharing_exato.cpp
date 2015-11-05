#include <cstdlib>
#include <cstdio>
#include <time.h>
#include "comb.h"
#include "graph.h"

using namespace std;

/*
 *
 * Temos um problema que � a determina��o da rota de V ve�culos e dos pickups de N passageiros nessa rota
 *
 * o custo total de execu��o ser� a quantidade de rotas poss�veis (dentro dos limites de tempo e espa�o do ve�culo) multiplicado pela quantidade de pickups poss�veis
 * em cada nova rota.
 *
 * O problema � que essa quantidade de pickups claramente n�o � fixa, j� que ao adotar outra rota, o ve�culo k poder� n�o ter mais
 * tantos passageiros para pegar.
 *
 * Cada rota ter� a seguinte configuracao 9-3-7-5-2-6 (cidades representadas por n�meros inteiros)
 * onde cada n�mero � uma localidade. ent�o cada localidade excluindo a primeira e a ultima pode ter uma carona em espera.
 * pelo enunciado do problema, n�o temos nenhuma localidade que tem descarga e carga ao mesmo tempo. mas isso � detalhe.
 *
 *
 * ent�o a id�ia geral do algoritmo exato �:
 *
 * 1)Gerar um conjunto de rotas iniciais via backtracking.
 * 2)dado que por exemplo, uma rota de um determinado carro passa por 6 localidades, excluindo a primeira e a ultima temos 4
 * possibilidades de pickup,
 * ent�o para uma mesma rota podemos enumerar todos os pickups poss�veis na forma de um n�mero bin�rio
 * 0001
 * 0010
 * 0011 etc
 * simplesmente vai fazendo isso e descartando os casos em que n�o d� certo (as restri��es brutais do problema).
 *
 * 2.2)ent�o, pra cada nova permuta��o das caronas. descarta a solu��o que subutiliza a capacidade dos carros.
 * 3)salva a solu��o num arquivo.
 * 4)compara a nova com a pior do arquivo, se a nova solu��o � melhor do que a porrada de solu��es do arquivo, descarta todos esses.
 * 5)e assim vai, gerando todas as permuta��es de caronas nas cidades e comparando com o que t� no arquivo.
 * a compara��o no arquivo tem que ser r�pida, ent�o usamos a arvore bin�ria, etc.
 *
 * ent�o, depois de fazer tudo isso, repetimos o loop alterando uma das rotas via backtracking.
 * se apenas uma rota � alterada por vez, tem como diminuir o n�mero de combina��es de pickups?
 * provavalmente n�o importa. ent�o a essa altura, depois de gerar uma nova rota via bactracking, repete a coisa toda.
 *
 *
 */



int main_bak (){

	srand( (unsigned)time(NULL) );

	create_graph(5);

	vector< vector<int>* > * ofertas = gerar_permutacao(3);
	//vector< vector<int>* > * pedidos = gerar_combinacao(2);

	for (int i = 0; i < ofertas->size();i++){
		vector<int> *of = (*ofertas)[i];
		for (int j = 0; j < (*of).size(); of++){
			printf("%d ", (*of)[j]);
		}
		printf("\n");
	}

	//for (int i = 0; i < ofertas->size(); i++){
		//for (int j = 0; j < pedidos->size(); j++){
			//cout << "Processar\n";

			//S�o geradas duas solu��es
			//uma distribuindo as caronas igualmente entre cada oferta
			//e outra destribuindo o m�ximo de caronas pro primeiro ve�culo, assim sucessivamente
			//para os demais

		//}
	//}




	return 0;
}
