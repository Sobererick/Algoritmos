#include "Algoritmosmulti.h"
#include <vector>
#include <iostream>

using namespace std;



// Función para transponer una matriz
vector<vector<int>> transponerMatriz(const vector<vector<int>>& B) {
    int filas = B.size();
    int columnas = B[0].size();
    vector<vector<int>> B_transpuesta(columnas, vector<int>(filas));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            B_transpuesta[j][i] = B[i][j];
        }
    }

    return B_transpuesta;
}

// Algoritmo optimizado usando la transposición de la segunda matriz.
vector<vector<int>> multiplicacionMatricesOptimizada(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();

    // Transponer la matriz B
    vector<vector<int>> B_transpuesta = transponerMatriz(B);

    // Resultado es una matriz de n x m
    vector<vector<int>> C(n, vector<int>(m, 0));

    // Multiplicación optimizada
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                C[i][j] += A[i][k] * B_transpuesta[j][k];  // Acceso contiguo en B_transpuesta
            }
        }
    }

    return C;
}



