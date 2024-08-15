/*
Cálculo de la suma de los primeros n números naturales de forma recursiva.
Gilberto Malagamba Montejo - A00839075
15/08/2024
*/

#include <iostream>

int sumRecursive(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumRecursive(n - 1);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << sumRecursive(n) << std::endl;
    return 0;
}