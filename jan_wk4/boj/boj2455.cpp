//
// Created by 이승준 on 1/24/24.
//
#include <iostream>

using namespace std;

int main() {
    int sum = 0, off, on, maxSum = 0;
    for (int i = 0; i < 4; i++) {
        cin >> off;
        sum -= off;
        if (sum >= maxSum) {
            maxSum = sum;
        }
        cin >> on;
        sum += on;
        if (sum >= maxSum) {
            maxSum = sum;
        }
    }
    cout << maxSum;
}