/**
 * Aqui estou eu tentando
 * criar um algoritmo exato para o problema multiobjetivo do ridehsaring
 * chamado de Ridematching problm
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "graph.h"

/** data */

/*
int drivers_offers;
int riders_requests;
int trip_source[drivers_offers + riders_requests];
int trip_destination[drivers_offers + riders_requests];
float earlier_departure_time[drivers_offers + riders_requests];
float latest_arrival_time[drivers_offers + riders_requests];
float drivers_maximum_travel_time[drivers_offers];
float drivers_maximum_travel_distance[drivers_offers];
float riders_maximum_travel_time[riders_requests];
*/


/**
com - cidade origem do motorita
coc - cidade origem carona
cdm - cidade destino motorista
cdc - cidade destino carona
dmm - distancia máxima que o motorista pode percorrer
tmm - tempo máximo que o motorista pode percorrer
tmc - tempo máximo que o carona pode percorrer

Verifica todas as cidades de partida dos caronas x
>para cada cidade de partida do carona 'com'
>>para cada cidade de partida do motorista 'coc'
>> Computa a distancia e tempo entre com e coc
>> Se a menor distancia é maior do que dmm DESCARTA;
>> SENÃO Se o menor tempo é maior do que tmm DESCARTA;
>> Calcula a menor distância 'DIST' e o tempo 'TEMPO' entre a COC e CDM, passando por CDC
>>>isso significa encontrar a menor distancia entre COC - CDC e
>>>CDC - CDM
>> Se DIST é maior do que o dmm DESCARTA;
>> Se TEMPO é maior do que tmm DESCARTA;
>> Adiciona a solução à lista;


O objetivo agora é fazer todas as permutações, para permitir que
cada motorista tente atender uma combinação de carona diferente.


 */


/**
 * Resolvendo o problema para:
 * >1 motorista
 * >0 caronas
 *
 * 1 motorista
 * 1 carona
 *
 * 1 motorista
 * 2 caronas
 *
 * 2 motoristas
 * 2 caronas
 *
 * 2 motoristas
 * 3 caronas.//chegando nesse nível resolve pra n motoristas e m caronas
 *
 */


void init_data(){
	//int trip_source[drivers_offers + riders_requests];
	//int trip_destination[drivers_offers + riders_requests];
	//float earlier_departure_time[drivers_offers + riders_requests];
	//float latest_arrival_time[drivers_offers + riders_requests];
	//float drivers_maximum_travel_time[drivers_offers];
	//float drivers_maximum_travel_distance[drivers_offers];
	//float riders_maximum_travel_time[riders_requests];
}


int main(){

	srand( (unsigned)time(NULL) );

	create_graph(5);


	return 0;
}
