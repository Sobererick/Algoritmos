#include "Algoritmosdeordenamiento.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


void AnotarCSV(const string& filename, const string& algorithm, double time) {
    ofstream file;
    file.open(filename, ios::app); // Abre el archivo en modo append
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return;
    }
    file << algorithm << "," << time << "\n";
    file.close();
}