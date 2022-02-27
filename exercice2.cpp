#include <iostream>
#include <math.h>
#include <omp.h>
#include <vector>
#include <numeric>

#define N 100000000

static int threads = 1;

void sommes(int n) {

    std::vector<double> temps;
    for(int i=0;i<10;i++) {
        int sommes = 0;
        double startTime = omp_get_wtime();
#pragma omp parallel for num_threads(threads)
        for (int i = 0; i < n; i++) {
            sommes += i;
        }
        double endTime = omp_get_wtime();
        temps.push_back(endTime - startTime);
    }
    std::cout << "Temps de calcules pour la somme (moyenne de 10 exec) : " << (double)std::accumulate(temps.begin(), temps.end(), 0.0)/(double)temps.size() << "secondes" << std::endl;
}

void racineCarree(int n) {
    std::vector<double> temps;
    for(int i=0;i<10;i++) {
        double sommes = 0;
        double startTime = omp_get_wtime();
#pragma omp parallel for num_threads(threads)
        for (int i = 0; i < n; i++) {
            sommes += std::sqrt(i);
        }
        double endTime = omp_get_wtime();
        temps.push_back(endTime - startTime);
    }
    std::cout << "Temps de calcules pour la racine carrée (moy 10 exec) : " << (double)std::accumulate(temps.begin(), temps.end(), 0.0)/(double)temps.size() << "secondes" << std::endl;
}

void racineCarreeLog(int n) {

    std::vector<double> temps;
    for(int i=0;i<10;i++) {
        double sommes = 0;
        double startTime = omp_get_wtime();
#pragma omp parallel for num_threads(threads)
        for (int i = 0; i < n; i++) {
            sommes += std::sqrt(i) * std::log(i);
        }
        double endTime = omp_get_wtime();
        temps.push_back(endTime - startTime);
    }
    std::cout <<"Temps de calcules pour la racine carrée * log (moy 10 exec) : " <<  (double)std::accumulate(temps.begin(), temps.end(), 0.0)/(double)temps.size() << "secondes" << std::endl;
}

int main() {

    for(int i=1;i<17;i++) {
        threads = i;
        std::cout << "Execution pour " << i << " threads" << std::endl;
        sommes(N);
        racineCarree(N);
        racineCarreeLog(N);
    }

    return 0;
}

