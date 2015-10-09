#include <cstdlib>
#include <cstdio>
#include <time.h>
#include "comb.h"
#include "graph.h"

using namespace std;

int main (){

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
