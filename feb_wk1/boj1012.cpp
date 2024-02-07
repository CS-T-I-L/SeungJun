#include <iostream>

using namespace std;

bool field[50][50];
bool visited[50][50];
int n, m;

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || !field[i][j])
        return;
    visited[i][j] = true;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main() {
    int test, worms;
    cin >> test;
    while (test--) {
        int cnt = 0;
        cin >> n >> m >> worms;
        while (worms--) {
            int i, j;
            cin >> i >> j;
            field[i][j] = true;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && field[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                field[i][j] = false;
                visited[i][j] = false;
            }
        }
    }
}