/*
 * misc.c
 *
 *  Created on: 5 de out de 2015
 *      Author: Arthur
 */


int factorial_arranjo(int n){
	int result = 1;
	while (n > 0){
		for (int i = 0; i < n; i++){
			result = result * i;
		}
		n--;
	}
	return result;
};
