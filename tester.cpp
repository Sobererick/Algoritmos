#include "Algoritmosdeordenamiento.h"
#include "Algoritmosmulti.h"
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> // Para std::swap
#include <chrono>    // Para medir el tiempo

using namespace std;
using namespace std::chrono;

int main()
{
    int tipo;
    cout << "Hola, ¿que tipo algoritmo desea probar?" << endl;
    cout << "1. Tipo Ordenamiento" << endl;
    cout << "2. Tipo multiplicacion de matrices" << endl;
    cin >> tipo;
    

    switch (tipo) {
        case 1:{
        string filenamesave = "tiempos_ordenamiento.csv"; // Archivo CSV para tiempos de ordenamiento
        string filename;
        cout << "Ingrese el nombre del archivo CSV (ejemplo: datos2): ";
        cin >> filename;
            
        vector<int> data = readCSV(filename);
    
        if (data.empty())
        {
            cerr << "No data to sort." << endl;
            return 1;
        }

        int n = data.size();
        int *arr = new int[n];
        
        

            int tipo1;
            cout << "Algoritmos de ordenamientos disponibles \n";
            cout << "Opción 1 Selection sort\n";
            cout << "Opción 2 Mergesort\n";
            cout << "Opción 3 Quicksort \n";
            cout << "Opcion 4 Sort estandar \n";
            cin >> tipo1;


            switch (tipo1)
            {
                case 1:
                {
                    cout << "Selection sort\n";
                    copy(data.begin(), data.end(), arr); 
                    auto start = high_resolution_clock::now();

                    selectionSort(arr, n);

                    // Stop measuring time
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(stop - start); 
                    AnotarCSV(filenamesave, "Selection Sort", duration.count());

                    cout << "Sorted array: \n";
                    
                    printArray(arr, n);

                    cout << "Tiempo usado por selection sort: " << duration.count() << " milisegundos" << endl;

                    delete[] arr; 

                    break;
                }
            


            

                
                case 2:
                {
                    cout << "Mergesort\n";
                    auto start = high_resolution_clock::now();

                    mergeSort(data,0,n-1);

                    // Stop measuring time
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(stop - start); 
                    copy(data.begin(), data.end(), arr); 

                    cout << "Sorted array: \n";
                    printArray(arr, n);
                    cout << "Tiempo usado por Mergesort: " << duration.count() << " milisegundos" << endl;
                    AnotarCSV(filenamesave, "Mergesort", duration.count());

                    delete[] arr; 
                    break;
                }
            
        
                case 3:
                {
                    cout << "Quicksort\n";
                    auto start = high_resolution_clock::now();

                    quickSort(data,0,n-1);
                    // Stop measuring time
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(stop - start); 
                    copy(data.begin(), data.end(), arr); 
                    AnotarCSV(filenamesave, "Quicksort", duration.count());
                    cout << "Sorted array: \n";
                    printArray(arr, n);
                    cout << "Tiempo usado por Quicksort: " << duration.count() << " milisegundos" << endl;

                    delete[] arr; // Free allocated memory
                
                    break;
                }
                case 4:
                {
                    cout << "Sort estandar\n";
                    auto start = high_resolution_clock::now();
                    // Stop measuring time
                    sort(data.begin(),data.end());
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(stop - start); // Duration in milliseconds
                    copy(data.begin(), data.end(), arr); // Copy vector data to array
                    AnotarCSV(filenamesave, "Sort Estándar", duration.count());

                    cout << "Sorted array: \n";
                    printArray(arr, n);
                    cout << "Tiempo usado por sort: " << duration.count() << " milisegundos" << endl;

                    delete[] arr; // Free allocated memory

                    break;
                }
            
                default:
                    break;
        

            }
            break;
        
        }
        case 2:
        {
            int tipo2;
            cout << "Algoritmos de multiplicacion disponibles \n";
            cout << "Opción 1 Iterativo cubico\n";
            cout << "Opción 2 Algoritmo iterativo cúbico optimizado\n";
            cout << "Opción 3 Algoritmo de Strassen(no logre que funcionara correctamente)\n";
            cin >> tipo2;
            switch (tipo2)
            {
            case 1:
                {
                cout << "Iterativo cubico\n";
                vector<vector<int>> mat1, mat2;
                string filename1 = "matriz_A.csv";
                string filename2 = "matriz_B.csv";

                // Leer matrices desde los archivos CSV
                mat1 = readMatrixFromCSVFile(filename1);
                mat2 = readMatrixFromCSVFile(filename2);

                // Verificar si las dimensiones son compatibles para la multiplicación
                if (mat1[0].size() != mat2.size()) {
                cout << "Error: El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz." << endl;
                return 1;
                }
                auto start = high_resolution_clock::now();

                // Multiplicar las matrices
                mulMat(mat1,mat2);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);


                AnotarCSV("tiempos_multiplicacion.csv", "Multiplicación Iterativo Cúbico", duration.count());
                cout << "Tiempo usado por Multiplicación Iterativo Cúbico: " << duration.count() << " milisegundos" << endl;
                break;
                }
            
                    
                    
            case 2:
                {
                cout << "Algoritmo iterativo cúbico optimizado\n";
                vector<vector<int>> mat1, mat2;
                string filename1 = "matriz_A.csv";
                string filename2 = "matriz_B.csv";

                // Leer matrices desde los archivos CSV
                mat1 = readMatrixFromCSVFile(filename1);
                mat2 = readMatrixFromCSVFile(filename2);
                transponerMatriz(mat2);

                // Verificar si las dimensiones son compatibles para la multiplicación
                if (mat1[0].size() != mat2.size()) {
                cout << "Error: El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz." << endl;
                return 1;
                }

                // Multiplicar las matrices
                auto start = high_resolution_clock::now();
                vector<vector<int>> resultado = multiplicacionMatricesOptimizada(mat1,mat2);
                auto stop = high_resolution_clock::now();

                auto duration = duration_cast<milliseconds>(stop - start);
                cout<< "Matriz resultante: \n";
                for (int i = 0; i < resultado.size(); i++) {
                    for (int j = 0; j < resultado[0].size(); j++) {
                        cout << resultado[i][j] << "     ";
                    }
                    cout << endl;
                }
                AnotarCSV("tiempos_multiplicacion.csv", "Multiplicación Optimizada", duration.count());
                cout << "Tiempo usado por Multiplicación Optimizada: " << duration.count() << " milisegundos" << endl;


                break;
                }
            case 3:
                {
                cout << "Algoritmo de Strassen\n";
                
                vector<vector<int>> mat1, mat2;
                string filename1 = "matriz_A.csv";
                string filename2 = "matriz_B.csv";

                // Leer matrices desde los archivos CSV
                mat1 = readMatrixFromCSVFile(filename1);
                mat2 = readMatrixFromCSVFile(filename2);

                // Verificar si las dimensiones son compatibles para la multiplicación
                if (mat1[0].size() != mat2.size()) {
                cout << "Error: El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz." << endl;
                return 1;
                }

                // Multiplicar las matrices
                auto start = high_resolution_clock::now();
                vector<vector<int>> resultado = multiply_matrix(mat1,mat2);
                auto stop = high_resolution_clock::now();

                auto duration = duration_cast<milliseconds>(stop - start);
                cout<< "Matriz resultante: \n";
                for (int i = 0; i < resultado.size(); i++) {
                    for (int j = 0; j < resultado[0].size(); j++) {
                        cout << resultado[i][j] << "     ";
                    }
                    cout << endl;
                }
                AnotarCSV("tiempos_multiplicacion.csv", "Multiplicación Strassen", duration.count());
                cout << "Tiempo usado por Multiplicación Strassen: " << duration.count() << " milisegundos" << endl;

                // int rowsA, colsA, rowsB, colsB;
                // lld** matA = ReadMatrixFromCSV("matrixA.csv", rowsA, colsA);
                // lld** matB = ReadMatrixFromCSV("matrixB.csv", rowsB, colsB);


                break;
                }
            
            default:
                {
                break;
                }   
            }
        }

    }
    

    return 0;
}


