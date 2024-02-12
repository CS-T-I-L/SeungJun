#include <iostream>

using namespace std;

pair<int, int> king;
pair<int, int> stone;

bool isSame() {
    return king.first == stone.first && king.second == stone.second;
}

bool canMove(string cmd, pair<int, int>& k) {
    if (cmd == "R") return k.first != 8;
    if (cmd == "L") return k.first != 1;
    if (cmd == "B") return k.second != 1;
    if (cmd == "T") return k.second != 8;
    if (cmd == "RT") return k.first != 8 && k.second != 8;
    if (cmd == "LT") return k.first != 1 && k.second != 8;
    if (cmd == "RB") return k.first != 8 && k.second != 1;
    if (cmd == "LB") return k.first != 1 && k.second != 1;
    return false;
}

int charToInt(char c) {
    return (int) (c - 'A' + 1);
}

char intToChar(int i) {
    return (char) (i + 'A' - 1);
}

void move(string cmd, pair<int, int>& k) {
    if (cmd == "R" && k.first != 8)
        k.first++;
    else if (cmd == "L" && k.first != 1)
        k.first--;
    else if (cmd == "B" && k.second != 1)
        k.second--;
    else if (cmd == "T" && k.second != 8)
        k.second++;
    else if (cmd == "RT" && k.first != 8 && k.second != 8) {
        k.first++;
        k.second++;
    } else if (cmd == "LT" && k.first != 1 && k.second != 8) {
        k.first--;
        k.second++;
    } else if (cmd == "RB" && k.first != 8 && k.second != 1) {
        k.first++;
        k.second--;
    } else if (cmd == "LB" && k.first != 1 && k.second != 1) {
        k.first--;
        k.second--;
    }
}

string undo(string s) {
    string temp = s;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == 'R')
            temp[i] = 'L';
        else if (s[i] == 'L')
            temp[i] = 'R';
        else if (s[i] == 'T')
            temp[i] = 'B';
        else if (s[i] == 'B')
            temp[i] = 'T';
    }
    return temp;
}

int main() {
    string cmd;
    int moves;
    char kingChar, stoneChar;

    cin >> kingChar >> king.second >> stoneChar >> stone.second >> moves;
    king.first = charToInt(kingChar);
    stone.first = charToInt(stoneChar);

    while (moves--) {
        cin >> cmd;
        if (canMove(cmd, king)) {
            move(cmd, king);
            if (isSame() && canMove(cmd, stone)) {
                move(cmd, stone);
            }
            else if (isSame() && !canMove(cmd, stone)){
                move(undo(cmd), king);
            }
        }
    }

    cout << intToChar(king.first) << king.second << '\n'
         << intToChar(stone.first) << stone.second;
}
