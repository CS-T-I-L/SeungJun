#include <iostream>
#include <vector>

using namespace std;

char grid[8][8];

int changeToBlack() {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0 && grid[i][j] == 'W')
                cnt++;
            else if ((i + j) % 2 != 0 && grid[i][j] == 'B')
                cnt++;
        }
    }
    return cnt;
}

int changeToWhite() {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0 && grid[i][j] == 'B')
                cnt++;
            else if ((i + j) % 2 != 0 && grid[i][j] == 'W')
                cnt++;
        }
    }
    return cnt;
}

void cutGrid(vector<vector<char> > &v, int startX, int startY) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            grid[i][j] = v[startX + i][startY + j];
        }
    }
}

int main() {
    int rows, cols, min = 64;
    cin >> rows >> cols;

    vector<vector<char> > v(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i <= rows - 8; i++) {
        for (int j = 0; j <= cols - 8; j++) {
            cutGrid(v, i, j);
            int black = changeToBlack();
            int white = changeToWhite();
            if (black < min)
                min = black;
            if (white < min)
                min = white;
        }
    }

    cout << min;
}
