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
int N, cnt;
int m[1001];
vector<int> path;

void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        path.push_back(cur);
        q.pop();
        if (cur + m[cur] >= N) {
            cnt = path.size();
            break;
        }
        for (int i = m[cur]; i >= 1; i--) {
            if (m[cur + i] == 0) {
                continue;
            }
            q.push(cur + i);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }
    bfs();
    cout << cnt;
    return 0;
}