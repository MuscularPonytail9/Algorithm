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


int m[1002][1002];
bool v[1002][1002]; 
int N, M;
int temp;
int sp = 0;
int p = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, -1, 0, 1 };
int dayCount;
bool isFail;
queue<int> addNum;
vector <pair<int, int>> start;
void bfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < start.size(); i++) {
        q.push(start[i]);
    }
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int cx = current.first;
        int cy = current.second;
        v[cx][cy] = true;
        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx <= 0 || ny <= 0 || nx > N || ny > M || v[nx][ny] == true || m[nx][ny] == -1) {
                continue;
            }
            q.push({ nx, ny });
            v[nx][ny] = true;
            m[nx][ny] = 1;
            p++;
        }
        addNum.push(p);
        p = 0;
    }
}

int main() {
    cin >> M >> N;

    for (int i = 1; i < N+1; i++) {
        for (int j = 1; j < M + 1; j++) {
            cin >> temp;
            m[i][j] = temp;
            if (temp == 1) {
                start.push_back({ i,j });
                sp++;
            }
        }
    }
    if (sp == N * M) {
        cout << 0;
        return 0;
    }
    bfs();
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            if (m[i][j] == 0) {
                isFail = true;
            }
        }
    }
    if (isFail == true) {
        cout << -1;
    }
    else {
        while (!addNum.empty()) {
            int t = 0;
            for (int i = 0; i < sp; i++) {
                t += addNum.front();
                addNum.pop();
            }
            sp = t;
            dayCount++;
        }
        cout << dayCount - 1;
    }
    return 0;
}