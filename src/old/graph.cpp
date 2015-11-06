/*
 * graph.c
 *
 *  Created on: 5 de out de 2015
 *      Author: Arthur
 */
#include <cstdlib>
#include "graph.h"

//Cria uma matriz de adjacência de NxN vértices
vertex *** create_graph(int n){

	vertex*** matrix = (vertex***) malloc(sizeof(vertex**)*n);
	int label = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j) continue;
			matrix[i][j] = (vertex*)malloc(sizeof(vertex));
			matrix[i][j]->distance = 1 + ( rand() % 100 );
			matrix[i][j]->pai = NULL;
			matrix[i][j]->label = 68 + (label++);
		}
	}
	return matrix;
}
