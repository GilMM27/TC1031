/*
Cálculo de la cantidad de pasos necesarios para llegar a 1 en la conjetura de Collatz.
Gilberto Malagamba Montejo - A00839075
15/08/2024
*/

#include <iostream>

int o3nPlusOne(int n, int count = 1) {
    if (n == 1) {
        return count;
    }
    if (n % 2 == 0) {
        return o3nPlusOne(n / 2, count + 1);
    }
    return o3nPlusOne(3 * n + 1, count + 1);
}

int main() {
    for (int i = 2; i <= 100; i++) {
        std::cout << i << "\t" << o3nPlusOne(i) << std::endl;
    }
    return 0;
}