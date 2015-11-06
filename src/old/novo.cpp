/*
 * novo.cpp
 *
 *  Created on: 4 de nov de 2015
 *      Author: Arthur
 */


//Constantes
const float AT = 1;//tolerância fixa
const float BT = 1.1;//tolerância proporcional

typedef struct vtx{
	int demand;
	vtx* destiny;
	int hasRider;//0-1
	int ED;//Earliest Departure time
	int LA;//Latest Arrival time
	float MTT;//rider's maximum travel time
	float time_window[4];

} vertex;

float computeDistance(vertex* v){
	return 1;
}

void computeMTT(vertex* v){
	float distanceVertex = computeDistance(v);
	v->MTT = AT + BT * distanceVertex;
}

void computeTimeWindow(vertex* v){
	float distanceVertex = computeDistance(v);
	v->time_window[0] = v->ED;
	v->time_window[1] = v->LA - distanceVertex;
	v->time_window[2] = v->ED + distanceVertex;
	v->time_window[3] = v->LA;
}

void setup(int n_, int v_){
	int n = n_; //Riders qtd;
	int v = v_; //Veicles qtd;
	int R[n];//Riders vector; Contains the demand at i position
	int V[v];//Veicles vector;
	int A[n+n+v+v];//Locations vector;

}

int mainbacc(){

	return 0;
}
