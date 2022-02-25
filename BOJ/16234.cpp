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
vector<pair<int,int>> v;
int N, L, R;
int map[52][52];
bool visited[52][52];
int dj[4] = { 0, 1, 0, -1 };
int di[4] = { -1, 0, 1, 0 };
int temp;
int dayCnt;
int cnt;
void BFS() {
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == false) {
                int P = 0;
                int countryCnt = 0;
                q.push({ i,j });
                v.push_back({ i,j });
                P += map[i][j];
                countryCnt++;
                visited[i][j] = true;
                while (!q.empty()) {
                    auto currentPos = q.front();
                    int ci = currentPos.first;
                    int cj = currentPos.second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int ni = ci + di[k];
                        int nj = cj + dj[k];
                        if (ni < 0 || nj < 0 || ni >= N || nj >= N || visited[ni][nj] == true) {
                            continue;
                        }
                        if (L <= abs(map[ni][nj] - map[ci][cj]) && abs(map[ni][nj] - map[ci][cj]) <= R) {
                            cnt++;
                            q.push({ ni, nj });
                            v.push_back({ ni,nj });
                            countryCnt++;
                            P += map[ni][nj];
                            visited[ni][nj] = true;
                        }
                    }
                }
                if (v.size() > 1) {
                    for (int l = 0; l < v.size(); l++) {
                        map[v[l].first][v[l].second] = P / countryCnt;
                    }
                }               
                v.clear();
                P = 0;
            }
        }
    }
    for (int l = 0; l < N; l++) {
        for (int m = 0; m < N; m++) {
            visited[l][m] = false;
        }
    }
    if (cnt == 0) {
        cout << dayCnt;
    }
    else {
        dayCnt++;
        cnt = 0;
        BFS();
    }
}

int main() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            map[i][j] = temp;
        }
    }
    BFS();
    return 0;
}