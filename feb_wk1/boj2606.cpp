#include <iostream>
#include <queue>

using namespace std;

vector<int> network[100];
bool visited[100];

void bfs(int start) {
    int len = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int top = q.front();
        visited[top] = true;
        q.pop();
        for (auto c: network[top]) {
            if (!visited[c]) {
                q.push(c);
                visited[c] = true;
                len++;
            }
        }
    }
    cout << len;
}

int main() {
    int computers, connections;
    cin >> computers >> connections;

    while (connections--) {
        int start, end;
        cin >> start >> end;
        network[start].push_back(end);
        network[end].push_back(start);
    }

    bfs(1);
}
