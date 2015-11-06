/*
 * ridesharing.cpp
 *
 *  Created on: 5 de nov de 2015
 *      Author: Arthur
 */

#include<vector>
#include<iostream>
using namespace std;

typedef struct vtx{
	int id;
	int demand;
	vtx* destiny;
	int hasRider;//0-1
	int ED;//Earliest Departure time
	int LA;//Latest Arrival time
	int AT = 1;
	int BT = 1.1;
	float MTT;//rider's maximum travel time
	float time_window[4];

} vertex;

class Grafo{
public:
	vector< vector<float> > matrix;
	vector< vertex* > vertex_list;
	int n_vertex;
	//Constroi um grafo completo com n vértices
	Grafo(int n){
		n_vertex = n;
		matrix.resize(n, vector<float>(n));
		vertex_list.resize(n);
		for (int i = 0; i < n; i++){
			vertex_list[i] = new vertex();
		}
	}

	~Grafo(){
		for (int i = 0; i < n_vertex; i++){
			delete vertex_list[i];
		}
	}

	float distance(vertex* v1, vertex* v2){
		return matrix[v1->id][v2->id];
	}

};

Grafo* problema_minimo(){
	Grafo* g = new Grafo(6);

	g->matrix[0][0] = 0;
	g->matrix[0][1] = 1;
	g->matrix[0][2] = 1;
	g->matrix[0][3] = 1;
	g->matrix[0][4] = 1;
	g->matrix[0][5] = 1;

	g->matrix[1][0] = 0;
	g->matrix[1][1] = 0;
	g->matrix[1][2] = 1;
	g->matrix[1][3] = 1;
	g->matrix[1][4] = 1;
	g->matrix[1][5] = 1;

	g->matrix[2][0] = 0;
	g->matrix[2][1] = 1;
	g->matrix[2][2] = 0;
	g->matrix[2][3] = 1;
	g->matrix[2][4] = 1;
	g->matrix[2][5] = 1;

	g->matrix[3][0] = 0;
	g->matrix[3][1] = 1;
	g->matrix[3][2] = 1;
	g->matrix[3][3] = 0;
	g->matrix[3][4] = 1;
	g->matrix[3][5] = 1;

	g->matrix[4][0] = 0;
	g->matrix[4][1] = 1;
	g->matrix[4][2] = 1;
	g->matrix[4][3] = 1;
	g->matrix[4][4] = 0;
	g->matrix[4][5] = 1;

	g->matrix[5][0] = 0;
	g->matrix[5][1] = 1;
	g->matrix[5][2] = 1;
	g->matrix[5][3] = 1;
	g->matrix[5][4] = 1;
	g->matrix[5][5] = 1;



	vertex* v1 = g->vertex_list[0];
	vertex* v2 = g->vertex_list[3];
	v1->ED = 2;
	v1->LA = 10;
	v1->MTT = v1->AT + v1->BT * g->distance(v1, v2);
	v1->demand = 3;
	v1->destiny = v2;
	v1->hasRider = 1;
	v1->time_window[0] = v1->ED;
	v1->time_window[1] = v1->LA - v1->MTT;
	v1->time_window[2] = v1->ED + v1->MTT;
	v1->time_window[3] = v1->LA;


	cout << g->matrix[0][0];

}



int main(){
	Grafo* g = problema_minimo();

	delete g;

	return 0;
}
