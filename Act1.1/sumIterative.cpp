/*
Cálculo de la suma de los primeros n números naturales de forma iterativa.
Gilberto Malagamba Montejo - A00839075
15/08/2024
*/

#include <iostream>

int sumIterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    std::cout << sum << std::endl;
    return sum;
}

int main() {
    int n;
    std::cin >> n;
    sumIterative(n);
    return 0;
}