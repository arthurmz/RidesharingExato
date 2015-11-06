#include <iostream>
#include <vector>
#include "comb.h"

using namespace std;

//vector<int> index;
//
//
//void pretty_print(vector<int>* v) {
//  static int count = 0;
//  cout << "combination no " << (++count) << ": [ ";
//  for (int i = 0; i < v->size(); ++i) {
//	  cout << (*v)[i] << " ";
//  }
//  cout << "] " << endl;
//}
//
//void go(int offset, int k, vector<int>* combination, vector< vector<int>* > * comb_global) {
//  if (k == 0) {
//	vector<int> *newVector = new vector<int>(combination->begin(),combination->end());
//	(*comb_global).push_back(newVector);
//    pretty_print(combination);
//    return;
//  }
//  for (int i = 0; i < index.size(); ++i) {
//	bool jaTem = false;
//	for (int y = 0; y < combination->size(); y++){
//		if ((*combination)[y] == index[i]){
//			jaTem = true;
//		}
//	}
//	if (jaTem) continue;
//    combination->push_back(index[i]);
//    go(i+1, k-1, combination, comb_global);
//    combination->pop_back();
//  }
//}
//
//vector< vector<int>* >*  gerar_combinacao(int tamanho){
//
//	vector<int> *combinacao = new vector<int>;
//
//	vector< vector<int>* > * combinacao_global = new vector< vector<int>* >;
//	//const vector<int> index;
//
//	for (int i = 0; i < tamanho; ++i) {
//		index.push_back(i+1);
//	}
//	for (int z = 1; z <= tamanho; z++){
//		go(0,z, combinacao, combinacao_global);
//	}
//
//	return combinacao_global;
//}


bool has_value(vector<int> *partial, int depth, int value){
	for(int i = 0; i < depth; i++){
		if ((*partial)[i] == value) return true;
	}
	return false;
}

void helper(int n, int depth, vector<int> *partial, vector<vector<int>*> *global){
	if (depth == n){
		vector<int> *new_vector = new vector<int>(partial->begin(),partial->end());
		global->push_back(new_vector);
		return;
	}
	for (int i = 0; i < n; i++){
		if (!has_value(partial, depth, i)){
			(*partial)[depth] = i;
			helper(n, depth+1, partial, global);
		}
	}
}

/* Recebe o tamanho N do  subconjunto de inteiros
 * Retorna uma lista com todas as permutações desse subconjunto */
vector<vector<int>*>* gerar_permutacao(int n){

	vector<int> *partial = new vector<int>;
	for (int i = 0; i < n; i++){
		partial->push_back(i);
	}
	vector<vector<int>*> *global = new vector<vector<int>*>;

	helper(n, 0, partial, global);

	return global;
}



void helper_combinacao(int n, int depth, vector<int> *partial, vector<vector<int>*> *global){
	if (depth == n){
		return;
	}
	bool added = false;
	for (int i = 0; i < n; i++){
		if (!has_value(partial, depth, i)){
			added = true;
			partial->push_back(i);
			vector<int> *new_vector = new vector<int>(partial->begin(),partial->end());
			global->push_back(new_vector);
			helper(n, depth+1, partial, global);
		}
	}
	if (added)
		partial->pop_back();
}

vector<vector<int>*>* gerar_combinacao(int n){

	vector<int> *partial = new vector<int>;
	//for (int i = 0; i < n; i++){
	//	(*partial)[i] = i;
	//}
	vector<vector<int>*> *global = new vector<vector<int>*>;

	helper_combinacao(n, 0, partial, global);

	return global;

}


