#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <string> 
#include <cmath>
#include <cstdio>
#include <set>

using namespace std;
int N;
bool check;
int cnt;
vector<pair<int, int>> pos;
void bt(int col) {
    //cout << "bt(" << col << ") called" << '\n';
    if (col > N) {
        cnt++;
        //cout << "cnt" << '\n';
    }
    else {
        for (int row = 1; row <= N; row++) {
            //if (pos.empty()) {
            //    pos.push_back({ col, row });
            //    /*cout << "(" << col << ", " << row << ") inserted" << '\n';
            //    for (int i = 0; i < pos.size(); i++) {
            //        cout << "(" << pos[i].first << ", " << pos[i].second << ") ";
            //    }
            //    cout << '\n';*/
            //    bt(col + 1);
            //    pos.pop_back();
            //}
            //else {
                for (int i = 0; i < pos.size(); i++) {
                    if (row == pos[i].second || abs(col - pos[i].first) == abs(row - pos[i].second)) {
                        check = true;
                        break;
                    }
                }
                if (check != false) {
                    check = false;
                    continue;
                }
                pos.push_back({ col, row });
                /*cout << "(" << col << ", " << row << ") inserted" << '\n';
                for (int j = 0; j < pos.size(); j++) {
                    cout << "(" << pos[j].first << ", " << pos[j].second << ") ";
                }
                cout << '\n';*/
                bt(col + 1);
                pos.pop_back();
            //}
        }
    }
}

int main() {
    cin >> N;
    bt(1);
    cout << cnt;
    return 0;
}