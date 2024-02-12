#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[10001];
bool visited[10001];

int bfs(int start) {
    queue<int> q;
    int levels[101] { 0 };
    q.push(start);
    visited[start] = true;
    int count = 1;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (auto p : graph[top]) {
            if (!visited[p]) {
                q.push(p);
                visited[p] = true;
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        graph[y].push_back(x);
    }

    vector<int> v(10001, 0);
    for (int i = 1; i <= n; i++) {
        v[i] = bfs(i);
        for (int i = 0; i < 10001; i++) {
            visited[i] = false;
        }
    }

    vector<int> temp = v;
    sort(temp.begin(), temp.end());

    vector<int> maxIdx;
    int max = temp[10000];

    for (int i = 1; i <= n; i++) {
        if (v[i] >= max) {
            max = v[i];
            maxIdx.push_back(i);
        }
    }

    for (auto p : maxIdx) {
        cout << p << ' ';
    }
}
