//
// Created by 이승준 on 1/23/24.
//
#include <iostream>

using namespace std;

int n;
char grid[50][50];

int candyCnt() {
    int max = 0;

    for (int i = 0; i < n; i++) {
        int idx = 0, cnt = 1;
        while (idx + 1 < n) {
            if (grid[i][idx] == grid[i][idx + 1]) {
                cnt++;
            } else {
                if (max < cnt) { max = cnt; }
                cnt = 1;
            }
            idx++;
        }
        if (max < cnt) { max = cnt; }
    }

    for (int i = 0; i < n; i++) {
        int idx = 0, cnt = 1;
        while (idx + 1 < n) {
            if (grid[idx][i] == grid[idx + 1][i]) {
                cnt++;
            } else {
                if (max < cnt) { max = cnt; }
                cnt = 1;
            }
            idx++;
        }
        if (max < cnt) { max = cnt; }
    }

    return max;
}

bool canSwapRight(int r, int c) {
    if (c + 1 < n && grid[r][c] != grid[r][c + 1])
        return true;
    return false;
}

bool canSwapDown(int r, int c) {
    if (r + 1 < n && grid[r][c] != grid[r + 1][c])
        return true;
    return false;
}

void swapRight(int r, int c) {
    int a = grid[r][c + 1];
    grid[r][c + 1] = grid[r][c];
    grid[r][c] = a;
}

void swapDown(int r, int c) {
    int a = grid[r + 1][c];
    grid[r + 1][c] = grid[r][c];
    grid[r][c] = a;
}

int main() {
    int max = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (canSwapRight(i, j)){
                swapRight(i, j);
                if (max < candyCnt()) {max = candyCnt();}
                swapRight(i, j);
            }
            if (canSwapDown(i, j)){
                swapDown(i, j);
                if (max < candyCnt()) {max = candyCnt();}
                swapDown(i, j);
            }
        }
    }

    cout << max;
}