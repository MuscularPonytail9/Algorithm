﻿#ifndef _CRT_SECURE_NO_WARNINGS
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

int childNum[100];
int childList[100][5];
bool vis[100];
class stack {
public:
	int nextIdx;
	int array[50];
	void init() {
		nextIdx = 0;
		for (int i = 0; i < 50; i++) {
			array[i] = 0;
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
	void push_back(int payload) {
		array[nextIdx++] = payload;
	}
	int back() {
		return array[nextIdx - 1];
	}
	void pop_back() {
		nextIdx--;
		array[nextIdx] = 0;
	}
};

void dfs_init(int N, int path[100][2])
{
	for (int i = 0; i < 100; i++) {
		childNum[i] = 0;
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 5; j++) {
			childList[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			if (childList[path[i][0]][j] == 0) {
				childList[path[i][0]][j] = path[i][1];
				childNum[path[i][0]]++;
				break;
			}
		}
	}
}

int dfs(int n)
{
	for (int i = 0; i < 100; i++) {
		vis[i] = false;
	}
	int res = -1;
	stack v;
	v.init();
	vis[n] = true;
	v.push_back(n);
	while (!v.empty()) {
		int cur = v.back();
		if (cur > n) {
			res = cur;
			break;
		}
		v.pop_back();
		for (int i = childNum[cur] - 1; i >= 0; i--) {
			if (vis[childList[cur][i]] == false) {
				v.push_back(childList[cur][i]);
				vis[childList[cur][i]] = true;
			}
		}
	}
	return res;
}
static unsigned int seed = 12345;
static unsigned int pseudo_rand(int max) {
	seed = ((unsigned long long)seed * 1103515245 + 12345) & 0x7FFFFFFF;
	return seed % max;
}

#define MAX_N (40)
#define MAX_K (98)
#define MIN_N (2)
#define MAX_CHILD (5)

extern void dfs_init(int N, int path[MAX_N][2]);
extern int dfs(int k);

static int p[MAX_K + 2];
static int c[MAX_K + 2];
static int path[MAX_N][2];
static void makeTree(int n) {
	for (int i = 1; i < MAX_K + 2; ++i) {
		p[i] = c[i] = -1;
	}
	c[pseudo_rand(MAX_K + 1) + 1] = 0;
	for (int i = 0; i < n; ++i) {
		int pi = pseudo_rand(MAX_K + 1) + 1;
		while (c[pi] < 0 || c[pi] >= MAX_CHILD) {
			++pi;
			if (pi == MAX_K + 2)
				pi = 1;
		}
		int ci = pseudo_rand(MAX_K + 1) + 1;
		while (c[ci] >= 0) {
			++ci;
			if (ci == MAX_K + 2)
				ci = 1;
		}
		p[ci] = pi;
		++c[pi];
		c[ci] = 0;
	}
	bool check[MAX_K + 2] = { false };
	for (int i = 0; i < n; ++i) {
		int e = pseudo_rand(MAX_K + 1) + 1;
		while (check[e] || c[e] < 0 || p[e] == -1) {
			++e;
			if (e == MAX_K + 2)
				e = 1;
		}
		check[e] = true;
		path[i][0] = p[e];
		path[i][1] = e;
	}
}

int main() {
	setbuf(stdout, NULL);
	int T;
	//freopen("dfs_input.txt", "r", stdin);
	scanf("%d", &T);

	int totalScore = 0;
	for (int tc = 1; tc <= T; tc++) {
		int n, q;

		scanf("%d %d %d", &n, &q, &seed);

		makeTree(n - 1);
		dfs_init(n, path);

		bool check[MAX_K + 2] = { false };
		int score = 100;
		for (int i = 0; i < q; ++i) {
			int k, ret, correct;

			scanf("%d", &k);

			ret = dfs(k);

			scanf("%d", &correct);

			if (ret != correct)
				score = 0;
		}
		printf("#%d : %d\n", tc, score);
		totalScore += score;
	}
	printf("#total score : %d\n", totalScore / T);

	return 0;
}