#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int cnt = 0;
int m, n;
bool grid[100][100];
bool visited[100][100];

bool canPush(int i, int j) {
    if (i >= 0 && i < m && j >= 0 && j < n && !grid[i][j] && !visited[i][j]) {
        return true;
    }
    return false;
}

int bfs(int c, int r) {
    int size = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(c, r));
    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        visited[top.first][top.second] = true;
        size++;
        if (canPush(top.first, top.second + 1)) {
            visited[top.first][top.second + 1] = true;
            q.push(make_pair(top.first, top.second + 1));
        }
        if (canPush(top.first, top.second - 1)) {
            visited[top.first][top.second - 1] = true;
            q.push(make_pair(top.first, top.second - 1));
        }
        if (canPush(top.first + 1, top.second)) {
            visited[top.first + 1][top.second] = true;
            q.push(make_pair(top.first + 1, top.second));
        }
        if (canPush(top.first - 1, top.second)) {
            visited[top.first - 1][top.second] = true;
            q.push(make_pair(top.first - 1, top.second));
        }
    }
    return size;
}

int main() {
    int squares;
    cin >> m >> n >> squares;

    while (squares--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = b; i < d; i++) {
            for (int j = a; j < c; j++) {
                grid[i][j] = true;
            }
        }
    }

    int cnt = 0;
    vector<int> areas;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!grid[i][j] && !visited[i][j]) {
                areas.push_back(bfs(i, j));
                cnt++;
            }
        }
    }
    sort(areas.begin(), areas.end());

    cout << cnt << '\n';
    for (auto n : areas){
        cout << n << ' ';
    }
}