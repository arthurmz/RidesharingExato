/*
 * ridesharing.cpp
 *
 *  Created on: 5 de nov de 2015
 *      Author: Arthur
 */

#include<vector>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct vtx{
	//Common
	int id;
	float time_window[4];
	vtx* destiny;
	int ED;//Earliest Departure time
	int LA;//Latest Arrival time
	float AT;//variável de tempo A
	float BT;//Variável de tempo B

	//Rider=================================
	bool hasRider;
	int demand;//dmi
	float MTT;//rider's maximum travel time
	float s;//Service time si (tempo que gasta atendendo um rider)
	//Vehicle===============================
	bool hasVehicle;
	int C;//Capacity
	float AD;//variável de distância A
	float BD;//Variável de distância B
	float MTD;//maximum vehicle's travel distance

} vertex;

class Grafo{
public:
	float** time_matrix;
	float** distance_matrix;
	vertex* vertex_list;
	int n;
	//Constroi um grafo completo com n vértices
	Grafo(int n_) : n(n_) {
		time_matrix = (float**) malloc(sizeof(float*)*n);
		distance_matrix = (float**) malloc(sizeof(float*)*n);
		for(int i=0; i< n; i++){
			time_matrix[i] = (float*) malloc (sizeof(float)*n);
			distance_matrix[i] = (float*) malloc (sizeof(float)*n);
		}

		vertex_list = (vertex*) malloc(sizeof(vertex)*n);

		for (int i = 0; i < n; i++){
			vertex_list[i].id = i;
			vertex_list[i].AT = 0;
			vertex_list[i].BT = 1.3;
			vertex_list[i].AD = 0;
			vertex_list[i].BD = 1.3;
			vertex_list[i].s = 0;//tempo de serviço é zero para todos os riders
			vertex_list[i].demand = 1;//demanda é 1 para todos os riders
			vertex_list[i].hasRider = false;
			vertex_list[i].hasVehicle = false;
			vertex_list[i].demand = 0;
		}
	}

	~Grafo(){
		free(vertex_list);
		for (int i = 0; i < n; i++){
			free(time_matrix[i]);
			free(distance_matrix[i]);
		}
		free(distance_matrix);
		free(time_matrix);
	}
};

Grafo* problema_minimo(){
	Grafo* g = new Grafo(8);

	/*Configurando os tempos.*/
	g->time_matrix[0][0] = 0;
	g->time_matrix[0][1] = 1;
	g->time_matrix[0][2] = 7;
	g->time_matrix[0][3] = 3;
	g->time_matrix[0][4] = 4;
	g->time_matrix[0][5] = 3;

	g->time_matrix[1][0] = 1;
	g->time_matrix[1][1] = 0;
	g->time_matrix[1][2] = 5;
	g->time_matrix[1][3] = 8;
	g->time_matrix[1][4] = 4;
	g->time_matrix[1][5] = 6;

	g->time_matrix[2][0] = 7;
	g->time_matrix[2][1] = 5;
	g->time_matrix[2][2] = 0;
	g->time_matrix[2][3] = 3;
	g->time_matrix[2][4] = 9;
	g->time_matrix[2][5] = 5;

	g->time_matrix[3][0] = 3;
	g->time_matrix[3][1] = 8;
	g->time_matrix[3][2] = 3;
	g->time_matrix[3][3] = 0;
	g->time_matrix[3][4] = 6;
	g->time_matrix[3][5] = 1;

	g->time_matrix[4][0] = 4;
	g->time_matrix[4][1] = 4;
	g->time_matrix[4][2] = 9;
	g->time_matrix[4][3] = 6;
	g->time_matrix[4][4] = 0;
	g->time_matrix[4][5] = 4;

	g->time_matrix[5][0] = 3;
	g->time_matrix[5][1] = 6;
	g->time_matrix[5][2] = 5;
	g->time_matrix[5][3] = 1;
	g->time_matrix[5][4] = 4;
	g->time_matrix[5][5] = 0;

	/*Configurando as distancias.*/
	g->distance_matrix[0][0] = 0;
	g->distance_matrix[0][1] = 1;
	g->distance_matrix[0][2] = 7;
	g->distance_matrix[0][3] = 3;
	g->distance_matrix[0][4] = 4;
	g->distance_matrix[0][5] = 3;

	g->distance_matrix[1][0] = 1;
	g->distance_matrix[1][1] = 0;
	g->distance_matrix[1][2] = 5;
	g->distance_matrix[1][3] = 8;
	g->distance_matrix[1][4] = 4;
	g->distance_matrix[1][5] = 6;

	g->distance_matrix[2][0] = 7;
	g->distance_matrix[2][1] = 5;
	g->distance_matrix[2][2] = 0;
	g->distance_matrix[2][3] = 3;
	g->distance_matrix[2][4] = 9;
	g->distance_matrix[2][5] = 5;

	g->distance_matrix[3][0] = 3;
	g->distance_matrix[3][1] = 8;
	g->distance_matrix[3][2] = 3;
	g->distance_matrix[3][3] = 0;
	g->distance_matrix[3][4] = 6;
	g->distance_matrix[3][5] = 1;

	g->distance_matrix[4][0] = 4;
	g->distance_matrix[4][1] = 4;
	g->distance_matrix[4][2] = 9;
	g->distance_matrix[4][3] = 6;
	g->distance_matrix[4][4] = 0;
	g->distance_matrix[4][5] = 4;

	g->distance_matrix[5][0] = 3;
	g->distance_matrix[5][1] = 6;
	g->distance_matrix[5][2] = 5;
	g->distance_matrix[5][3] = 1;
	g->distance_matrix[5][4] = 4;
	g->distance_matrix[5][5] = 0;

	/*Configurando o motorista 1*/
	vertex* mt1 = &g->vertex_list[0];
	mt1->ED = 2;
	mt1->LA = 44;
	mt1->MTT = mt1->AT + (mt1->BT * g->time_matrix[0][6]);
	mt1->MTD = mt1->AD + (mt1->BD * g->distance_matrix[0][6]);
	mt1->destiny = &g->vertex_list[6];
	mt1->hasVehicle = true;
	mt1->time_window[0] = mt1->ED;
	mt1->time_window[1] = mt1->LA - mt1->MTT;
	mt1->time_window[2] = mt1->ED + mt1->MTT;
	mt1->time_window[3] = mt1->LA;

	/*Configurando o motorista 2*/
	vertex* mt2 = &g->vertex_list[2];
	mt2->ED = 7;
	mt2->LA = 30;
	mt2->MTT = mt2->AT + (mt2->BT * g->time_matrix[2][4]);
	mt2->MTD = mt2->AD + (mt2->BD * g->distance_matrix[2][4]);
	mt2->destiny = &g->vertex_list[4];
	mt2->hasVehicle = true;
	mt2->time_window[0] = mt2->ED;
	mt2->time_window[1] = mt2->LA - mt1->MTT;
	mt2->time_window[2] = mt2->ED + mt1->MTT;
	mt2->time_window[3] = mt2->LA;

	/*Configurando o carona 1*/
	vertex* rider1 = &g->vertex_list[7];
	rider1->ED = 7;
	rider1->LA = 30;
	rider1->MTT = rider1->AT + (rider1->BT * g->time_matrix[7][3]);
	rider1->destiny = &g->vertex_list[3];
	rider1->hasRider = true;
	rider1->time_window[0] = rider1->ED;
	rider1->time_window[1] = rider1->LA - mt1->MTT;
	rider1->time_window[2] = rider1->ED + mt1->MTT;
	rider1->time_window[3] = rider1->LA;

	/*Configurando o carona 2*/
	vertex* rider2 = &g->vertex_list[1];
	rider2->ED = 12;
	rider2->LA = 15;
	rider2->MTT = rider2->AT + (rider2->BT * g->time_matrix[1][5]);
	rider2->destiny = &g->vertex_list[5];
	rider2->hasRider = true;
	rider2->time_window[0] = rider2->ED;
	rider2->time_window[1] = rider2->LA - mt1->MTT;
	rider2->time_window[2] = rider2->ED + mt1->MTT;
	rider2->time_window[3] = rider2->LA;


	return g;
}



int main(){
	Grafo* g = problema_minimo();

	g->time_matrix[2][0] = 21;

	cout << g->time_matrix[2][0] << endl;

	cout << g->vertex_list[1].id;

	delete g;

	return 0;
}
