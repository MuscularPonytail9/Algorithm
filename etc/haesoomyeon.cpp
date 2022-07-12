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
#include <map>
#include <functional>
#include <time.h>

using namespace std;
int T, temp2;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
vector<int> result;
void BFS(int N) {
    int map[102][102];
    int temp, label;
    int maxHeight = 0;
    int maximum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> temp;
            maxHeight = max(temp, maxHeight);
            map[i][j] = temp;
        }
    }
    for (int year = 0; year <= maxHeight; year++) {
        queue<pair<int, pair<int, int>>> q;
        bool visited[104][104] = {};
        label = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] > year && visited[i][j] == false) {
                    label++;
                    q.push({ label , { i, j } });
                    visited[i][j] = true;
                    while (!q.empty()) {
                        auto k = q.front();
                        q.pop();
                        auto currentPos = k.second;
                        int currentX = currentPos.first;
                        int currentY = currentPos.second;
                        for (int l = 0; l < 4; l++) {
                            int nextX = currentX + dx[l];
                            int nextY = currentY + dy[l];
                            if (map[nextX][nextY] <= year || nextX < 1 || nextX > N || nextY < 1 || nextY > N || visited[nextX][nextY] == true) {
                                continue;
                            }
                            q.push({ label ,{ nextX, nextY } });
                            visited[nextX][nextY] = true;
                        }
                    }
                }
            }
        }
        maximum = max(label, maximum);
    }
    result.push_back(maximum);
}
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> temp2;
        BFS(temp2);
    }
    for (int i = 1; i <= T; i++) {
        cout << "#" << i << " " << result[i - 1] << '\n';
    }
    return 0;
}