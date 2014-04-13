#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h"

int main() {
	int weights[8] = {2, 3, 5, 2, 4, 6, 3, 1};
	int values[8] = {5, 8, 14, 6, 13, 17, 10, 4};
	// 8 objects, maximum value = 12
	printf("Maximal value: %d\n", solveKnapsack(8, weights, values, 12));
	return 0;
}
