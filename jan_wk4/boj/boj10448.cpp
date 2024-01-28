//
// Created by 이승준 on 1/26/24.
//
#include <iostream>

using namespace std;

int eureka[45];

bool isThree(int target, int idx, int cnt) {
    if (target == 0 && cnt == 3)
        return true;
    if (target <= 0 || idx >= 50 || cnt == 3)
        return false;

    return isThree(target - eureka[idx], idx, cnt + 1) || isThree(target, idx + 1, cnt);
}


int main() {
    for (int i = 0; i < 45; i++) {
        eureka[i] = (int) (i * (i + 1) / 2);
    }

    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;

        cout << (isThree(n, 1, 0) ? 1 : 0) << '\n';
    }
}

//asdf