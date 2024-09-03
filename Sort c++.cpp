#include <iostream>
#include <algorithm> // Para std::sort
#include <vector>    // Para std::vector

int main() {
    // Creamos un vector de enteros
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    // Imprimimos el vector antes de ordenar
    std::cout << "Vector antes de ordenar: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Usamos std::sort para ordenar el vector
    std::sort(arr.begin(), arr.end());

    // Imprimimos el vector después de ordenar
    std::cout << "Vector después de ordenar: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
