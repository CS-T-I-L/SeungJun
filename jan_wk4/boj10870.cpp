//
// Created by 이승준 on 1/24/24.
//
#include <iostream>

using namespace std;

int main() {
    int fib[21];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < 21; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int n;
    cin >> n;
    cout << fib[n];
}