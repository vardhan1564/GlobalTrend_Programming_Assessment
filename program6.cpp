#include <iostream>

unsigned long long factorial(int n) {
    if (n < 0) {

        return -1;
    }

    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    unsigned long long fact = factorial(number);
    if (fact == -1) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        std::cout << "Factorial of " << number << " is " << fact << std::endl;
    }
    return 0;
}
