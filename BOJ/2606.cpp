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


int m[102][102];
bool v[102]; 
int N, M;
int t1, t2;
int num;
void bfs() {
    queue<int> q;
    int current = 1;
    q.push(1);
    v[1] = true;
    while (!q.empty()) {
        current = q.front();
        q.pop();
        for (int i = 1; i < N + 1; i++) {
            if (m[current][i] == 1 && v[i] == false) {
                q.push(i);
                v[i] = true;
                num++;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> t1 >> t2;
        m[t1][t2] = 1;
        m[t2][t1] = 1;
    }

    bfs();

    cout << num;
    return 0;
}