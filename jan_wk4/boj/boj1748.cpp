//
// Created by 이승준 on 1/24/24.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, digitSum = 0;
    long long totalDigits[8];

    for (int i = 0; i < 8; i++) {
        int numbers = (pow(10, i + 1) - pow(10, i));
        totalDigits[i] = (i + 1) * numbers;
    }

    cin >> x;
    int p = 0;
    while (x >= pow(10, p+1)) {
        digitSum += totalDigits[p];
        p++;
    }
    int leftNumbers = x - pow(10, p) + 1;
    digitSum += (leftNumbers * (p + 1));

    cout << digitSum;
}