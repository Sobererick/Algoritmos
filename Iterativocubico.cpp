// C++ program to multiply two matrices

#include "Algoritmosmulti.h"
#include <bits/stdc++.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> readMatrixFromCSVFile(const string& filename) {
    vector<vector<int>> matrix;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        return matrix; // Retorna una matriz vacía en caso de error
    }

    while (getline(file, line)) {
        vector<int> row;
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(stoi(cell)); // Convierte el valor a entero y lo agrega a la fila
        }
        matrix.push_back(row); // Agrega la fila a la matriz
    }

    file.close();
    return matrix;
}








void mulMat(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int R1 = mat1.size();         // Número de filas de mat1
    int R2 = mat2.size();         // Número de filas de mat2
    int C2 = mat2[0].size();      // Número de columnas de mat2

    vector<vector<int>> rslt(R1, vector<int>(C2, 0));  // Matriz resultado R1 x C2

    cout << "Multiplicación de las dos matrices dadas es:\n";

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < R2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
            cout << rslt[i][j] << "\t";
        }
        cout << endl;
    }
}



// This code is contributed by Manish Kumar (mkumar2789)


//modifique los parametros de la funcion para que reciba vectores de vectores
//funcion original aqui

// void mulMat(int mat1[][C1], int mat2[][C2])
// {
//     int rslt[R1][C2];

//     cout << "Multiplication of given two matrices is:\n";

//     for (int i = 0; i < R1; i++) {
//         for (int j = 0; j < C2; j++) {
//             rslt[i][j] = 0;

//             for (int k = 0; k < R2; k++) {
//                 rslt[i][j] += mat1[i][k] * mat2[k][j];
//             }

//             cout << rslt[i][j] << "\t";
//         }

//         cout << endl;
//     }
// }

