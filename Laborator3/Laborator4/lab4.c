#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int inverse_shuffle(int N, int number) {
    if (number % 2 == 0) {
        number >>= 1;
    } else {
        number >>= 1;
        number += N / 2;
    }

    return number;
}

void Benes(int N, int input, int output) {
    int etaje = log2(N) * 2 - 1;
    int input_after_commute;
    int output_before_commute;
    char first[10], last[10];

    // Un singur etaj
    if (etaje == 1) {
        if (input == output) {
            printf("Direct ");
        } else {
            printf("Cross ");
        }
    } else { // 3 etaje sau mai mult
        // Tratam intrarea
        if (output < N / 2) { // Upper half 
            if (input % 2 == 0) {
                strcpy(first, "Direct ");
                input_after_commute = input;
            } else {
                strcpy(first, "Cross ");
                input_after_commute = input - 1;
            }
        }
        if (output >= N / 2) { // Lower half 
            if (input % 2 == 0) {
                strcpy(first, "Cross ");
                input_after_commute = input + 1;
            } else {
                strcpy(first, "Direct ");
                input_after_commute = input;
            }
        }
        // Normalizare
        if (abs(input - output) >= N / 2) {
            input = N - input;
        }
        // Tratam iesirea
        if (input < N / 2) { // Upper half
            if (output % 2 == 0) {
                strcpy(last, "Direct ");
                output_before_commute = output;
            } else {
                strcpy(last, "Cross ");
                output_before_commute = output - 1;
            }
        }
        if (input >= N / 2) { // Lower half
            if (output % 2 == 0) {
                strcpy(last, "Cross ");
                output_before_commute = output + 1;
            } else {
                strcpy(last, "Direct ");
                output_before_commute = output;
            }
        }
        // Tratam mijlocul
        int interm_input = inverse_shuffle(N, input_after_commute) % (N / 2);
        int interm_output = inverse_shuffle(N, output_before_commute) % (N / 2);     

        printf("%s", first);
        Benes(N / 2, interm_input, interm_output);
        printf("%s", last);
    }  
}

int main() {
	int N, numar_conexiuni;

	printf("Dimensiunea retelei: "); scanf("%d", &N);
	printf("Numar conexiuni: "); scanf("%d", &numar_conexiuni);

	int in[numar_conexiuni], out[numar_conexiuni];

	for (int i = 0; i < numar_conexiuni; i++) {
		scanf("%d %d", &in[i], &out[i]);
	}

	for (int i = 0; i < numar_conexiuni; ++i) {
        printf("%d -> %d: ", in[i], out[i]);
        Benes(N, in[i], out[i]);
        printf("\n");
    }
    return 0;
}