#include <iostream>
#include <cmath>

int main() {
    // #1
    for (int i = 0; i <= 255; i++) {
        std::cout << "symbol code - " << i << ": " << static_cast<char>(i) << std::endl;
    }
    // #2
    std::cout << "Enter a symbol: ";
    unsigned char input;
    std::cin >> input;
    if (input >= 48 && input <= 57) {
        std::cout << "The entered symbol is a number" << std::endl;
    }
    else if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122)) {
        std::cout << "The entered symbol is a letter" << std::endl;
    }
    else std::cout << "The entered symbol is unknown" << std::endl;
    // #3
    std::cout << "Enter a number: ";
    int num;
    std::cin >> num;
    std::cout << "y(x) = ";
    switch (num % 4) {
        case 0: std::cout << 0 << std::endl; break;
        case 1: std::cout << num + 1 << std::endl; break;
        case 2: std::cout << -num << std::endl; break;
        case 3: std::cout << 2 * num << std::endl; break;
    }
    // #4
    std::cout << "Enter X: ";
    float x;
    std::cin >> x;
    if (x < 0.0f || x >= 1.0f) {
        std::cout << "This X is not valid for this function" << std::endl;
        return 0;
    }
    float ideal = 1 / pow((1 - x), 3);
    for (int i = -2; i >= -6; i--) {
        float result = 1;
        int n = 3;
        while (fabs(ideal - result) > pow(10, i)) {
            result += ((n - 1) * n * pow(x, n - 2)) / 2;
            n++;
        }
        std::cout << "Needed " << n - 2 << " iterations to reach accuracy E = 10^" << i << ", the result is " << result << std::endl;
    }
    return 0;
}
