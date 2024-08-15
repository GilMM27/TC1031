/*
Cálculo de la suma de los primeros n números naturales de forma directa.
Gilberto Malagamba Montejo - A00839075
15/08/2024
*/

#include <iostream>

int directSum(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << directSum(n) << std::endl;
    return 0;
}