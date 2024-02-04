#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, x;
    while (cin >> n){
        if (n == 0)
            break;
        vector<int> v;
        vector<int> temp{ 1,1,1,1,1,1 };
        for (int i{ 0 }; i < n - 6; i++){
            temp.push_back(0);
        }
        while (n--){
            cin >> x;
            v.push_back(x);
        }
        do{
            for (int i{ 0 }; i < v.size(); i++){
                if (temp[i])
                    cout << v[i] << ' ';
            }
            cout << '\n';
        } while (prev_permutation(temp.begin(), temp.end()));
        v.clear();
        temp.clear();
        cout << '\n';
    }
}