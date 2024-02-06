#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[101];
bool visited[101];

void dfs(int start) {
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main() {
    int ver;
    cin >> ver;
    for (int i = 0; i < ver; i++) {
        for (int j = 0; j < ver; j++) {
            int n;
            cin >> n;
            if (n == 1)
                graph[i].push_back(j);
        }
    }

    for (int i = 0; i < ver; i++) {
        fill(visited, visited + ver, false);
        dfs(i);
        for (int j = 0; j < ver; j++) {
            cout << visited[j] << ' ';
        }
        cout << '\n';
    }
}
