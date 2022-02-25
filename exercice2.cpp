#include <iostream>
#include <math.h>
#include <omp.h>

#define THREADS 8
#define N 100000000

void sommes(int n) {
    int sommes = 0;
    double startTime = omp_get_wtime();
#pragma omp parallel for num_threads(THREADS)
    for (int i = 0; i < n; i++) {
        sommes += i;
    }
    double endTime = omp_get_wtime();
    std::cout << endTime - startTime << "secondes" << std::endl;
}

void racineCarree(int n) {
    double sommes = 0;
    double startTime = omp_get_wtime();
#pragma omp parallel for num_threads(THREADS)
    for (int i = 0; i < n; i++) {
        sommes += sqrt(i);
    }
    double endTime = omp_get_wtime();
    std::cout << endTime - startTime << "secondes" << std::endl;
}

void racineCarreeLog(int n) {
    double sommes = 0;
    double startTime = omp_get_wtime();
#pragma omp parallel for num_threads(THREADS)
    for (int i = 0; i < n; i++) {
        sommes += sqrt(i) * log(i);
    }
    double endTime = omp_get_wtime();
    std::cout << endTime - startTime << "secondes" << std::endl;
}

int main() {

    sommes(N);
    racineCarree(N);
    racineCarreeLog(N);

    return 0;
}

