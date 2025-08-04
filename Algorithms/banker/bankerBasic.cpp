#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include <iomanip>

using Mat= std::vector<std::vector<int>>;
using Vec= std::vector<int>;

void mostrarVextor(const Vec& v, const std::string& nombre){
    std::cout << nombre << ": ";
    for (int x : v) {
        std:: cout << x << " ";   
    }
    std::cout << '\n';
}

void mostrarEstado(const Mat&, const Mat& alloc,
                    const Mat& need, const Vec& avail) {
    int n= max.size(), m= avail.size();


                    
    std::cout << "\n=== ESTADO ===\n";
    std::cout << "Proceso |   Max   | Allocation |  Need  \n";
    std::cout << "-----------------------------------------\n";
    for(int =0; i<n; i++0){
        std:cout<< "P" << i << std::setw(6) << "| ";
        for(int j=0; j<m; j++){
            std:: cout<< max[i][j] <<" ";
        }
        for(int j=0; j<m; j++){
            std:: cout<< alloc[i][j] <<" ";
        }
        for (int j=0; j<m; j++){
            std:: cout<< need[i][j] <<" ";
        }
    }
    for(int j=0; j<m; j++){
        std:: cout<< avail[j] <<" ";
    }
    std::cout << '-----------------\n';
}

bool esSeguro(const Mat& alloc, const Mat& need, const Vec& work) {
    int n = alloc.size();         // Número de procesos
    int m = work.size();          // Número de recursos

    std::vector<bool> finish(n, false);  // Vector para marcar procesos que ya terminaron
    Vec workCopy = work;                 // Hacemos una copia de work, ya que lo modificamos

    while (true) {
        bool progreso = false;

        for (int i = 0; i < n; i++) {
            if (finish[i]) continue;

            // Verificamos si el proceso i puede ejecutarse
            bool puede = true;
            for (int j = 0; j < m; j++) {
                if (need[i][j] > workCopy[j]) {
                    puede = false;
                    break;
                }
            }

            // Si puede ejecutarse, simulamos su ejecución
            if (puede) {
                for (int j = 0; j < m; j++) {
                    workCopy[j] += alloc[i][j];  // Libera recursos
                }
                finish[i] = true;
                progreso = true;
            }
        }

        // Si en esta iteración no se avanzó, rompemos el ciclo
        if (!progreso) break;
    }

    // Si todos los procesos pudieron finalizar, el estado es seguro
    return std::all_of(finish.begin(), finish.end(), [](bool f) { return f; });
}