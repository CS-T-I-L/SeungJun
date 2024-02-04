#include <iostream>
#include <vector>

using namespace std;

vector<int> comb(6);

void printVector() {
    for (int i = 0; i < 6; i++) {
        cout << comb[i] << ' ';
    }
    cout << '\n';
}

void combination(vector<int> &v, int depth, int next) {
    if (depth == 6) {
        printVector();
        return;
    }
    for (int i = next; i < v.size(); i++) {
        comb[depth] = v[i];
        combination(v, depth + 1, i + 1);
    }
}

int main() {
    int k, n;
    while (true) {
        cin >> k;
        if (k == 0) break;
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }
        combination(v, 0, 0);
        cout << '\n';
    }
}