#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int shuffle(int i, int intrari) {
	return (int)(2 * i + floor(2 * i / intrari)) % intrari;
}

int main() {
	
	int numar_intrari, numar_conexiuni;

	printf("Numar intrari: "); scanf("%d", &numar_intrari);
	printf("Numar conexiuni: "); scanf("%d", &numar_conexiuni);

	int in[numar_conexiuni], out[numar_conexiuni];

	for (int i = 0; i < numar_conexiuni; i++) {
		scanf("%d %d", &in[i], &out[i]);
	}

	int etaje = ceil(log2((double)numar_intrari));
	int matrix[numar_intrari][etaje + 1];
	memset(matrix, 0, sizeof(int) * numar_intrari * (etaje + 1));

	for (int i = 0; i < numar_conexiuni; ++i) {
		int xor = in[i] ^ out[i];

		printf("%d -> %d: ", in[i], out[i]);

		in[i] = shuffle(in[i], numar_intrari);

		if (matrix[in[i]][0]) {

			printf("Conflict");

		} else {

			matrix[in[i]][0] = 1;

			for (int j = 0; j < etaje; ++j) {
				// Verific bit-ul corespunzator etaj-ului
				int aux = xor & (1 << (etaje - j - 1));

				// Direct
				if (aux == 0) {
					in[i] = shuffle(in[i], numar_intrari);

					if (matrix[in[i]][j + 1]) {
						printf("Conflict ");
						break;
					} else {
						matrix[in[i]][j + 1] = 1;
						printf("Direct ");
					}
				}
				// Cross
				else {
					if (in[i] % 2 == 0) {
						++in[i];
					} else {
						--in[i];
					}

					in[i] = shuffle(in[i], numar_intrari);

					if (matrix[in[i]][j + 1]) {
						printf("Conflict ");
						break;
					} else {
						matrix[in[i]][j + 1] = 1;
						printf("Cross ");
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}
