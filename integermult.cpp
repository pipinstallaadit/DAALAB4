#include <iostream>
#include <cmath>
using namespace std;

int getSize(int num) {
    int size = 0;
    while (num != 0) {
        num /= 10;
        size++;
    }
    return size;
}

int karatsubaMultiply(int x, int y) {
    if (x < 10 || y < 10)
        return x * y;

    int n = min(getSize(x), getSize(y));
    int m = n / 2;

    int high1 = x / pow(10, m);
    int low1 = x % (int)pow(10, m);
    int high2 = y / pow(10, m);
    int low2 = y % (int)pow(10, m);

    int z0 = karatsubaMultiply(low1, low2);
    int z1 = karatsubaMultiply((low1 + high1), (low2 + high2));
    int z2 = karatsubaMultiply(high1, high2);

    return z2 * pow(10, 2 * m) + (z1 - z2 - z0) * pow(10, m) + z0;
}

int main() {
    int num1, num2;
    cout << "Enter first integer: ";
    cin >> num1;
    cout << "Enter second integer: ";
    cin >> num2;

    int result = karatsubaMultiply(num1, num2);
    cout << "Product: " << result << endl;

    return 0;
}
