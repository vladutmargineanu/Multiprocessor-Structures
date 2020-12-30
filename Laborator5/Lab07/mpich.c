#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    srand(time(NULL));
    int in_points = 0;
    int out_points = 0;

    for (int i = 0; i < 10000000; i++) {
        double x = (rand()  % 100) / 100.0;
        double y = (rand()  % 100) / 100.0;
        // If we are inside the Circle
        if ((x - 0.5) * (x - 0.5) + (y - 0.5) * (y - 0.5) <= 0.5 * 0.5) {
            in_points++;
        }
        else {
            out_points++;
        }
    }

    double pi = 4.0 * in_points / (in_points + out_points);
    double res[world_size];

    if (world_rank != 0) {
        MPI_Send(&pi, 1, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
    }
    else {
        for (int i = 1; i < world_size; i++) {
            MPI_Recv(&res[i], 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        res[0] = pi;
        pi = 0;
        for (int i = 0 ; i < world_size; ++i) {
            pi += res[i];
        }
        pi /= 1.0 * world_size;
        printf("%lf\n", pi);
    }

    // Finalize the MPI environment.
    MPI_Finalize();
}
