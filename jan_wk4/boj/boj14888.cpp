//
// Created by 이승준 on 1/27/24.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, maxResult{ -1000000000 }, minResult{ 1000000000 };
    queue<int> num;
    vector<char> op;
    cin >> n;
    for (int i{ 0 }; i < n; i++)
    {
        cin >> x;
        num.push(x);
    }
    for (int i{ 0 }; i < 4; i++)
    {
        cin >> x;
        while (x--)
        {
            if (i == 0)
                op.push_back('+');
            else if (i == 1)
                op.push_back('-');
            else if (i == 2)
                op.push_back('*');
            else
                op.push_back('/');
        }
    }

    vector<int> permu(n - 1);
    for (size_t i{ 0 }; i < permu.size(); i++)
    {
        permu[i] = i;
    }
    do
    {
        queue<int> num_copy = num;
        int result = num_copy.front();
        num_copy.pop();

        for (int i{ 0 }; i < n - 1; i++)
        {
            char c = op[permu[i]];
            int right = num_copy.front();
            num_copy.pop();

            if (c == '+')
                result += right;
            else if (c == '-')
                result -= right;
            else if (c == '*')
                result *= right;
            else
                result /= right;
        }

        maxResult = max(maxResult, result);
        minResult = min(minResult, result);

    } while (next_permutation(permu.begin(), permu.end()));

    cout << maxResult << '\n' << minResult;
}
//asdfasdf