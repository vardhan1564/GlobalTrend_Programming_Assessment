#include <iostream>


int sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    int sum = sumOfDigits(number);
    std::cout << "Sum of the digits of " << number << " is " << sum << std::endl;

    return 0;
}
