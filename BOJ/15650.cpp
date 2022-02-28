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
int N, M;
vector<int> result;
bool v[10];
void bt(int index) {
    if (index == M + 1) {
        for (int i = 1; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << '\n';
    }
    else {
        for (int i = 1; i <= N; i++) {
            if (v[i] == true || result[index-1] >= i) {
                continue;
            }
            else {
                result.push_back(i);
                v[i] = true;
                bt(index + 1);
                v[i] = false;
                result.pop_back();
            }
        }
    }
}

int main() {
    cin >> N >> M;
    result.push_back(0);
    bt(1);
    return 0;
}