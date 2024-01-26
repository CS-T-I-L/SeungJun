//
// Created by 이승준 on 1/27/24.
//
//
// Created by 이승준 on 1/26/24.
//
#include <iostream>

using namespace std;

int main() {
    char adrian[3] = {'A', 'B', 'C'};
    char bruno[4] = {'B', 'A', 'B', 'C'};
    char goran[6] = {'C', 'C', 'A', 'A', 'B', 'B'};

    int adrianScore = 0;
    int brunoScore = 0;
    int goranScore = 0;

    int len;
    cin >> len;
    for (int i = 0; i < len; i++) {
        char answer;
        cin >> answer;
        if (answer == adrian[i % 3])
            adrianScore++;
        if (answer == bruno[i % 4])
            brunoScore++;
        if (answer == goran[i % 6])
            goranScore++;
    }

    int max = 0;
    if (max < adrianScore)
        max = adrianScore;
    if (max < brunoScore)
        max = brunoScore;
    if (max < goranScore)
        max = goranScore;

    cout << max << '\n';
    if (max == adrianScore)
        cout << "Adrian\n";
    if (max == brunoScore)
        cout << "Bruno\n";
    if (max == goranScore)
        cout << "Goran\n";
}//aaa