#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    const int num_elements = 1000; // 10^6 elementos
    const int min_value = 0;
    const int max_value = 1000;

    std::ofstream file("datitos.csv");  // Abrir el archivo CSV para escritura

    if (!file) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    std::srand(std::time(nullptr));  // Inicializar la semilla para números aleatorios

    for (int i = 0; i < num_elements; ++i) {
        int random_number = std::rand() % (max_value - min_value + 1) + min_value;
        file << random_number;
        if (i < num_elements - 1) {
            file << ",";  // Separar los números con comas
        }
    }

    file.close();  // Cerrar el archivo

    std::cout << "Archivo CSV generado con " << num_elements << " números aleatorios." << std::endl;

    return 0;
}
