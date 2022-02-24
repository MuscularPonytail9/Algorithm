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

int N, M, k;
int map[102][102];
bool visited[102][102];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
vector<int> S;
int sectionCnt;
int sectionArea;


void BFS() {
    queue<pair<int, int>> q;
    for (int x = 0; x < M; x++) {
        for (int y = 0; y < N; y++) {
            if (visited[x][y] == false && map[x][y] == 0) {
                q.push({ x,y });
                visited[x][y] = true;
                sectionCnt++;
                while (!q.empty()) {
                    auto currentPos = q.front();
                    int cx = currentPos.first;
                    int cy = currentPos.second;
                    q.pop();
                    sectionArea++;
                    for (int i = 0; i < 4; i++) {
                        int nx = cx + dx[i];
                        int ny = cy + dy[i];
                        if (nx < 0 || ny < 0 || nx > M-1 || ny > N-1 || visited[nx][ny] == true || map[nx][ny] == 1) {
                            continue;
                        }
                        q.push({ nx, ny });
                        visited[nx][ny] = true;
                    }
                }
                S.push_back(sectionArea);
                sectionArea = 0;
            }
        }
    }
    
}

int main() {
    int x1, y1, x2, y2;
    cin >> M >> N >> k;
    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j < y2; j++) {
            for (int l = x1; l < x2; l++) {
                map[j][l] = 1;
            }
        }
    }
    BFS();
    sort(S.begin(), S.end());
    cout << sectionCnt << '\n';
    for (int i = 0; i < sectionCnt; i++) {
        cout << S[i] << ' ';
    }
    return 0;
}