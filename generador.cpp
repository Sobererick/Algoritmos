#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

// Función para generar números aleatorios
int randomInt(int min, int max) {
    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

// Función para escribir una matriz en un archivo CSV
void writeMatrixToCSV(const std::vector<std::vector<int>>& matrix, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }

    for (const auto& row : matrix) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) file << ",";
        }
        file << "\n";
    }
    file.close();
}

// Función para escribir un dataset en un archivo CSV
void writeDatasetToCSV(const std::vector<std::vector<int>>& dataset, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }

    for (const auto& row : dataset) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) file << ",";
        }
        file << "\n";
    }
    file.close();
}


// Función para generar un dataset medianamente ordenado
void createDatasetMedianamenteOrdenado(int num_elements, int min_value, int max_value, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }

    std::srand(std::time(nullptr));

    std::vector<int> data(num_elements);
    for (int i = 0; i < num_elements; ++i) {
        data[i] = std::rand() % (max_value - min_value + 1) + min_value;
    }

    // Ordenar la primera mitad en orden ascendente
    std::sort(data.begin(), data.begin() + num_elements / 2);

    // Desordenar la segunda mitad
    std::random_shuffle(data.begin() + num_elements / 2, data.end());

    // Escribir los datos al archivo CSV
    for (size_t i = 0; i < data.size(); ++i) {
        file << data[i];
        if (i < data.size() - 1) {
            file << ",";
        }
    }

    file.close();
    std::cout << "Archivo CSV '" << filename << "' generado con " << num_elements << " números (primera mitad ordenada y segunda mitad desordenada)." << std::endl;
}

// Función para generar y multiplicar matrices con dimensiones personalizadas
void createMatricesAndMultiply() {
    int rowsA, colsA, colsB;
    std::cout << "Introduce el número de filas de la matriz A: ";
    std::cin >> rowsA;
    std::cout << "Introduce el número de columnas de la matriz A (y filas de la matriz B): ";
    std::cin >> colsA;
    std::cout << "Introduce el número de columnas de la matriz B: ";
    std::cin >> colsB;

    std::vector<std::vector<int>> matrixA(rowsA, std::vector<int>(colsA));
    std::vector<std::vector<int>> matrixB(colsA, std::vector<int>(colsB));
    std::vector<std::vector<int>> matrixC(rowsA, std::vector<int>(colsB, 0));

    for (auto& row : matrixA) {
        for (auto& elem : row) {
            elem = randomInt(0, 100);
        }
    }

    for (auto& row : matrixB) {
        for (auto& elem : row) {
            elem = randomInt(0, 100);
        }
    }

    writeMatrixToCSV(matrixA, "matriz_A.csv");
    writeMatrixToCSV(matrixB, "matriz_B.csv");

    std::cout << "Matrices creadas. Resultados guardados en 'matriz_A.csv', 'matriz_B.csv'." << std::endl;
}

// Función para generar un CSV con tamaño y rango personalizados
void generateCSV(int num_elements, int min_value, int max_value, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }

    std::srand(std::time(nullptr));

    for (int i = 0; i < num_elements; ++i) {
        int random_number = std::rand() % (max_value - min_value + 1) + min_value;
        file << random_number;
        if (i < num_elements - 1) {
            file << ",";
        }
    }

    file.close();
    std::cout << "Archivo CSV '" << filename << "' generado con " << num_elements << " números aleatorios." << std::endl;
}

int main() {
    int option;
    do {
        std::cout << "Selecciona una opción:" << std::endl;
        std::cout << "1. Crear dataset desordenado" << std::endl;
        std::cout << "2. Crear dataset medianamente ordenado" << std::endl;
        std::cout << "3. Crear matrices" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Opción: ";
        std::cin >> option;

        switch (option) {
            case 1:{
                int num_elements, min_value, max_value;
                std::string filename;

                std::cout << "Introduce el número de elementos: ";
                std::cin >> num_elements;
                std::cout << "Introduce el valor mínimo: ";
                std::cin >> min_value;
                std::cout << "Introduce el valor máximo: ";
                std::cin >> max_value;
                std::cout << "Introduce el nombre del archivo CSV (ejemplo: datos_personalizados.csv): ";
                std::cin >> filename;

                generateCSV(num_elements, min_value, max_value, filename);
                break;
            }
            case 2:{
                int num_elements, min_value, max_value;
                std::string filename;

                std::cout << "Introduce el número de elementos: ";
                std::cin >> num_elements;
                std::cout << "Introduce el valor mínimo: ";
                std::cin >> min_value;
                std::cout << "Introduce el valor máximo: ";
                std::cin >> max_value;
                std::cout << "Introduce el nombre del archivo CSV (ejemplo: datos_personalizados.csv): ";
                std::cin >> filename;

                generateCSV(num_elements, min_value, max_value, filename);
                break;
            }
            case 3:
                createMatricesAndMultiply();
                break;
            case 4:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Inténtalo de nuevo." << std::endl;
                break;
        }
    } while (option != 4);

    return 0;
}
