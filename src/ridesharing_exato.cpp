#include <cstdlib>
#include <cstdio>
#include <time.h>
#include "comb.h"
#include "graph.h"

using namespace std;

/*
 *
 * Temos um problema que é a determinação da rota de V veículos e dos pickups de N passageiros nessa rota
 *
 * o custo total de execução será a quantidade de rotas possíveis (dentro dos limites de tempo e espaço do veículo) multiplicado pela quantidade de pickups possíveis
 * em cada nova rota.
 *
 * O problema é que essa quantidade de pickups claramente não é fixa, já que ao adotar outra rota, o veículo k poderá não ter mais
 * tantos passageiros para pegar.
 *
 * Cada rota terá a seguinte configuracao 9-3-7-5-2-6 (cidades representadas por números inteiros)
 * onde cada número é uma localidade. então cada localidade excluindo a primeira e a ultima pode ter uma carona em espera.
 * pelo enunciado do problema, não temos nenhuma localidade que tem descarga e carga ao mesmo tempo. mas isso é detalhe.
 *
 *
 * então a idéia geral do algoritmo exato é:
 *
 * 1)Gerar um conjunto de rotas iniciais via backtracking.
 * 2)dado que por exemplo, uma rota de um determinado carro passa por 6 localidades, excluindo a primeira e a ultima temos 4
 * possibilidades de pickup,
 * então para uma mesma rota podemos enumerar todos os pickups possíveis na forma de um número binário
 * 0001
 * 0010
 * 0011 etc
 * simplesmente vai fazendo isso e descartando os casos em que não dá certo (as restrições brutais do problema).
 *
 * 2.2)então, pra cada nova permutação das caronas. descarta a solução que subutiliza a capacidade dos carros.
 * 3)salva a solução num arquivo.
 * 4)compara a nova com a pior do arquivo, se a nova solução é melhor do que a porrada de soluções do arquivo, descarta todos esses.
 * 5)e assim vai, gerando todas as permutações de caronas nas cidades e comparando com o que tá no arquivo.
 * a comparação no arquivo tem que ser rápida, então usamos a arvore binária, etc.
 *
 * então, depois de fazer tudo isso, repetimos o loop alterando uma das rotas via backtracking.
 * se apenas uma rota é alterada por vez, tem como diminuir o número de combinações de pickups?
 * provavalmente não importa. então a essa altura, depois de gerar uma nova rota via bactracking, repete a coisa toda.
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

			//São geradas duas soluções
			//uma distribuindo as caronas igualmente entre cada oferta
			//e outra destribuindo o máximo de caronas pro primeiro veículo, assim sucessivamente
			//para os demais

		//}
	//}




	return 0;
}
