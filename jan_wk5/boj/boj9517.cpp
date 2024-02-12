#include <iostream>

using namespace std;

int main() {
    char isCorrect;
    int start, questions, timeSpent, timeLeft{210};
    cin >> start >> questions;

    while (questions--) {
        cin >> timeSpent >> isCorrect;
        timeLeft -= timeSpent;
        if (timeLeft <= 0)
            break;
        if (isCorrect == 'T') {
            int next = (++start) % 8;
            start = (next == 0 ? 8 : next);
        }
    }

    cout << start;
}