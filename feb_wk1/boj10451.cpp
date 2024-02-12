#include <iostream>

using namespace std;

int graph[1001];
bool visited[1001];

void dfs(int start) {
    visited[start] = true;
    int next = graph[start];
    if (!visited[next] && graph[next] != 0)
        dfs(next);
}

int main() {
    int test, len, n;
    cin >> test;
    while (test--) {
        int cnt = 0;
        cin >> len;
        for (int i = 1; i <= len; i++) {
            cin >> graph[i];
        }
        for (int i = 1; i <= len; i++) {
            if (!visited[i]) {
                dfs(i);
                cnt++;
            }
        }
        for (int i = 1; i <= len; i++) {
            graph[i] = 0;
            visited[i] = false;
        }
        cout << cnt << '\n';
    }
}