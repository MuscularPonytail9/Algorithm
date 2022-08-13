#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <array>
#include <string>

using namespace std;

struct Node {
	int dist;
	int x;
	int y;
};

class queue {
public:
	int nextIdx;
	Node array[60];
	void init() {
		nextIdx = 0;
		for (int i = 0; i < 60; i++) {
			array[i].dist = 0;
			array[i].x = 0;
			array[i].y = 0;
		}
	}
	bool empty() {
		if (nextIdx == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void push(int dist, int x, int y) {
		array[nextIdx].dist = dist;
		array[nextIdx].x = x;
		array[nextIdx].y = y;
		nextIdx++;
	}
	Node front() {
		return array[0];
	}
	Node back() {
		return array[nextIdx - 1];
	}
	void pop() {
		nextIdx--;
		for (int i = 0; i <= nextIdx && i < 59; i++) {
			array[i].dist = array[i + 1].dist;
			array[i].x = array[i + 1].x;
			array[i].y = array[i + 1].y;
		}
	}
};

int m[11][11];
bool vis[11][11];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs_init(int map_size, int map[10][10]) {
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			m[i][j] = map[i - 1][j - 1];
		}
	}
}
int bfs(int x1, int y1, int x2, int y2) {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			vis[i][j] = false;
		}
	}
	int res = -1;
	queue q;
	q.init();
	q.push(0, y1, x1);
	while (!q.empty()) {
		Node cur = q.front();
		if (cur.x == y2 && cur.y == x2) {
			res = cur.dist;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 1 || ny < 1 || nx > 10 || ny > 10 || m[nx][ny] == 1 || vis[nx][ny] == true) {
				continue;
			}
			q.push(cur.dist + 1, nx, ny);
			vis[nx][ny] = true;
		}
	}
	return res;
}

extern void bfs_init(int N, int map[10][10]);
extern int bfs(int x1, int y1, int x2, int y2);

static int test_bfs() {
	int N;
	int map[10][10];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	bfs_init(N, map);
	int M;
	int score = 100;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int result = bfs(x1, y1, x2, y2);
		int dist;
		scanf("%d", &dist);
		if (result != dist) score = 0;
	}
	return score;
}

int main() {
	setbuf(stdout, NULL);

	printf("#total score : %d\n", test_bfs());

	return 0;
}