#include <iostream>

using namespace std;

int n, m;
bool ocean[50][50];
bool visited[50][50];

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || !ocean[i][j] || visited[i][j])
        return;
    visited[i][j] = true;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i + 1, j + 1);
    dfs(i - 1, j - 1);
    dfs(i - 1, j + 1);
    dfs(i + 1, j - 1);
}

int main() {
    while (true) {
        int cnt = 0;
        cin >> m >> n;
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> ocean[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ocean[i][j] && !visited[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ocean[i][j] = false;
                visited[i][j] = false;
            }
        }
    }
}