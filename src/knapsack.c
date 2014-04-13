#include "knapsack.h"
#include <stdio.h>

static int max(int a, int b);

/*******************************/

static int max(int a, int b) {
	return (a < b) ? b : a;
}

int solveKnapsack(int nbObjects, int weights[], int values[], int maxValue) {
	int M[nbObjects][maxValue+1];
	int i, j;
	
	// Initialization of M
	for (j = 0 ; j <= maxValue ; j++) {
		if (weights[0] > j)
			M[0][j] = 0;
		else
			M[0][j] = values[0];
	}
	
	for (i = 1 ; i < nbObjects ; i++) {
		for (j = 0 ; j <= maxValue ; j++) {
			if (weights[i] > j)
				M[i][j] = M[i-1][j];
			else
				M[i][j] = max(M[i-1][j], M[i-1][j-weights[i]]+values[i]);
		}
	}
	
	i = nbObjects-1, j = maxValue;
	
	while (M[i][j] == M[i][j-1])
		j--;
		
	while (j > 0) {
		while ((i > 0) && (M[i][j] == M[i-1][j]))
			i--;
			
		j -= weights[i];
		
		if (j >= 0)
			printf("%d\n", i+1);
		
		i--;
	}
	
	return M[nbObjects-1][maxValue];
}
