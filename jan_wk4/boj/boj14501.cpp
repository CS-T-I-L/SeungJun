//
// Created by 이승준 on 1/27/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n;
    vector<pair<int, int>> timeTable(n + 1);
    vector<int> profitList(n + 2, 0);

    for (int i{ 1 }; i <= n; i++)
    {
        cin >> x >> y;
        timeTable[i] = make_pair(x, y);
    }

    for (int i { n }; i >= 1; i--)
    {
        int nextDay = i + timeTable[i].first;
        if (nextDay <= n + 1)
        {
            profitList[i] = max(profitList[i + 1], timeTable[i].second + profitList[nextDay]);
        }
        else
        {
            profitList[i] = profitList[i + 1];
        }
    }

    cout << profitList[1] << endl;
}
