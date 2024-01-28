//
// Created by 이승준 on 1/24/24.
//
#include <iostream>

using namespace std;

int cnt = 0;
int n, target;
int numbers[20];

void findTarget(int idx, int sum) {
    if(idx == n) {
        if(sum == target) {
            cnt++;
        }
        return;
    }

    findTarget(idx+1, sum+numbers[idx]);
    findTarget(idx+1, sum);
}

int main() {
    cin >> n >> target;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    findTarget(0, 0);

    if(target == 0) cnt--;

    cout << cnt;
}
