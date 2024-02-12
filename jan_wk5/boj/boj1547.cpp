#include <iostream>

using namespace std;

int main() {
    int ballCup = 1;
    int moves, x, y;
    cin >> moves;

    while (moves--) {
        cin >> x >> y;
        if (x == ballCup)
            ballCup = y;
        else if (y == ballCup)
            ballCup = x;
    }

    cout << ballCup;
}