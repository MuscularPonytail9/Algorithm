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
string s;
int map[52][52];
bool v[52][52];
queue<pair<pair<int, int>, int>> q;
int MAX = 0;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int dis;
void BFS() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 1 && v[i][j] == false) {
				q.push({ {i,j}, 0 });
				v[i][j] = true;
				while (!q.empty()) {
					auto k = q.front();
					int ci = k.first.first;
					int cj = k.first.second;
					dis = k.second;
					if (MAX < dis) {
						MAX = dis;
					}
					q.pop();
					for (int m = 0; m < 4; m++) {
						int ni = ci + di[m];
						int nj = cj + dj[m];
						if (map[ni][nj] == 0 || ni < 1 || nj < 1 || ni > N || nj > M || v[ni][nj] == true) continue;
						q.push({ {ni, nj}, dis + 1 });
						v[ni][nj] = true;
					}
				}
				dis = 0;
				for (int o = 1; o <= N; o++) {
					for (int p = 1; p <= M; p++) {
						v[o][p] = false;
					}
				}
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'L') {
				map[i][j + 1] = 1;
			}
		}
	}
	BFS();
	cout << MAX;
	return 0;
}