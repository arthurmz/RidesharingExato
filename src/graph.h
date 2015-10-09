/*
 * graph.h
 *
 *  Created on: 5 de out de 2015
 *      Author: Arthur
 */

#ifndef GRAPH_H_
#define GRAPH_H_

typedef struct vtx{
	char label; // 'A' 'B' 'C'..
	int distance;
	struct vtx * pai;
} vertex;

typedef struct trp{
	vertex * source;
	vertex * target;
} trip;


vertex *** create_graph(int n);



#endif /* GRAPH_H_ */
