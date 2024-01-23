//
// Created by 이승준 on 1/24/24.
//
#include <iostream>

using namespace std;

int main() {
    int ppl;
    int grid[50][3];
    cin >> ppl;

    for (int i = 0; i < ppl; i++) {
        cin >> grid[i][0] >> grid[i][1];
    }

    int rank = 0;
    for (int i = 0; i < ppl; i++) {
        int weight = grid[i][0];
        int height = grid[i][1];
        for (int j = 0; j < ppl; j++) {
            if (i == j) { continue; }
            if (grid[j][0] > weight && grid[j][1] > height) {
                rank++;
            }
        }
        grid[i][2] = rank + 1;
        rank = 0;
    }
    for (int i = 0; i < ppl; i++) {
        cout << grid[i][2] << ' ';
    }
}