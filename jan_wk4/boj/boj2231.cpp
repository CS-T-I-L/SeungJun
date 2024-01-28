//
// Created by 이승준 on 1/24/24.
//
#include <iostream>

using namespace std;

int getSum(int x) {
    int sum = x;
    while (x >= 1) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    bool found = false;
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        if (getSum(i) == n) {
            cout << i;
            found = true;
            break;
        }
    }

    if (!found) { cout << 0; }
}

