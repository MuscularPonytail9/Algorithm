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
int m[1102];
bool v[1102];
bool suc = false;
void bfs() {
    queue <pair<int, int>> q;
    q.push({ 1, 0 });
    v[1] = true;
    while (!q.empty()) {
        auto k = q.front();
        int cur = k.first;
        int jump = k.second;
        q.pop();
        if (cur + m[cur] >= N) {
            cout << jump + 1;
            suc = true;
            break;
        }
        for (int i = m[cur]; i >= 1; i--) {
            if (m[cur + i] == 0 || v[cur + i] == true) {
                continue;
            }
            q.push({ cur + i, jump + 1 });
            v[cur + i] = true;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }
    if (N == 1) {
        cout << 0;
        return 0;
    }
    bfs();

    if (suc == false) {
        cout << -1;
    }
    return 0;
}