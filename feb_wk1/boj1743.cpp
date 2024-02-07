#include <iostream>
#include <queue>

using namespace std;

int n, m;
int maxSize = 0;
bool path[100][100];
bool visited[100][100];

bool canPush(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || !path[i][j])
        return false;
    return true;
}

void bfs(int i, int j) {
    int size = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        if (visited[top.first][top.second])
            continue;
        visited[top.first][top.second] = true;
        size++;
        if (canPush(top.first, top.second + 1))
            q.push(make_pair(top.first, top.second + 1));
        if (canPush(top.first, top.second - 1))
            q.push(make_pair(top.first, top.second - 1));
        if (canPush(top.first + 1, top.second))
            q.push(make_pair(top.first + 1, top.second));
        if (canPush(top.first - 1, top.second))
            q.push(make_pair(top.first - 1, top.second));
    }
    if (size > maxSize)
        maxSize = size;
}

int main() {
    int trash;
    cin >> n >> m >> trash;
    while (trash--) {
        int i, j;
        cin >> i >> j;
        path[i - 1][j - 1] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && path[i][j])
                bfs(i, j);
        }
    }
    cout << maxSize;
}