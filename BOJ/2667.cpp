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

int di[4] = { -1,0,1,0 }; 
int dj[4] = { 0,1,0, -1 };

vector<int> res;
int map[27][27];
bool v[27][27]; 
int N;
int num = 0;
void bfs() {
    queue<pair<int, int>> q;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (v[i][j] == false && map[i][j] == 1) {
                q.push({ i,j });
                v[i][j] = true;
                num++;
                while (!q.empty()) {
                    auto t = q.front();
                    q.pop();
                    int ti = t.first;
                    int tj = t.second;

                    for (int k = 0; k < 4; k++) {
                        int ni = ti + di[k];
                        int nj = tj + dj[k];
                        if (ni <= 0 || nj <= 0 || ni > N || nj > N || map[ni][nj] == 0 || v[ni][nj]==true) continue;

                        q.push({ ni,nj });
                        v[ni][nj] = true;
                        num++;
                    }
                }
                res.push_back(num);
                num = 0;
            }
        }
    }
    
}

int main() {
    cin >>N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    bfs();
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto k : res) {
        cout << k << '\n';
    }

    return 0;
}