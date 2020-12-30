#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main_done() {
	int n = 4;
	int a[4][4], b[4][4], c[4][4] = { 0 };
	int v[4][4][4] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = b[i][j] = 1;
		}
	}

	/* CRCW - PRAM */
	printf("CRCW - PRAM\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("Initializare c pentru %i %i\n", i, j);
			int sum  = 0;
			for (int k = 0; k < n; k++) {
				printf("Calcularea c[%i][%i] pentru k = %i\n", i, j, k);
				sum += a[i][k] * b[k][j];
				printf("\tc[%i][%i] = %d\n", i, j, c[i][j]);
			}
			printf("Scrierea pentru c[%i][%i]\n", i, j);
			c[i][j] = sum;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}	

	/* CREW - PRAM */
	printf("CREW - PRAM\n");

	printf("Etapa 1:\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				printf("Calculare si scriere v[%i][%i][%i]\n", i, j, k);
				v[i][j][k] = a[i][k] * b[k][j];
				printf("\tv[%i][%i][%i] = %d\n", i, j, k, v[i][j][k]);
			}
		}
	}

	printf("Final etapa 1.\n");

	printf("Etapa 2:\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int m = 0; m < log2(n); m++) {
				for (int k = 0; k < n; k++) {
					if (k % (int)pow(2, m + 1) == 0) {
						printf("Scriere in v[%i][%i][%i] pentru m = %i\n", i, j, k, m);
						v[i][j][k] += v[i][j][k + (int)pow(2, m)];
						printf("\tv[%i][%i][%i] = %d\n", i, j, k, v[i][j][k]);
					}
				}
			}
			c[i][j] = v[i][j][0];
		}
	}

	printf("Final etapa 2.\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}