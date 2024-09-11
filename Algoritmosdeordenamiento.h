#ifndef ALGORITMOS_ORDENAMIENTO_H
#define ALGORITMOS_ORDENAMIENTO_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Declaración de las funciones
void selectionSort(int arr[], int n);  // Función Selección  // Función Selección
void merge(vector<int>& arr, int left, int mid, int right);  // Función Merge
void mergeSort(vector<int>& arr, int left, int right);  // Función MergeSort
void printVector(vector<int>& arr);  // Función para imprimir un vector
void quickSort(vector<int>& arr, int low, int high);  // Función QuickSort
int partition(vector<int>& arr, int low, int high);   // Función auxiliar para QuickSort
vector<int> readCSV(const string &filename);  // Función para leer un archivo CSV
void printArray(int arr[], int n);  // Función para imprimir un arreglo
void AnotarCSV(const string& filename, const string& algorithm, double time);  // Función para anotar en un archivo CSV

#endif
