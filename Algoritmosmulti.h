#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Funciones de generación de matrices
// Funciones de multiplicación de matrices
void mulMat(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2);
vector<vector<int>> readMatrixFromCSVFile(const string& filename);
vector<vector<int>> transponerMatriz(const vector<vector<int>>& B);
vector<vector<int>> multiplicacionMatricesOptimizada(const vector<vector<int>>& A, const vector<vector<int>>& B);
vector<vector<int> >
multiply_matrix(vector<vector<int> > matrix_A,vector<vector<int> > matrix_B);
