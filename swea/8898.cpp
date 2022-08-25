#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <string>
#include <stdio.h>
#include <cstring>
#include <climits>

using namespace std;
vector<int>cowPos;

int bs(int payload) {
	int low = 0;
	int high = cowPos.size() - 1;
	int mid = (low + high) / 2;

	if (payload < cowPos[low]) {
		return low;
	}
	if (cowPos[high] < payload) {
		return high;
	}
	while (low <= high) {
		mid = (low + high) / 2;
		if (cowPos[mid] == payload) {
			return mid;
		}
		else if (cowPos[mid] < payload) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	if (cowPos[mid] < payload) {
		mid++;
	}
	return mid;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cowPos.clear();
		int N, M;
		int mini = 100000022;
		int cnt = 0;
		int c1, c2;
		int horPos, cowIndex;
		cin >> N >> M >> c1 >> c2;
		int num = abs(c1 - c2);
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			cowPos.push_back(temp);
		}
		sort(cowPos.begin(), cowPos.end());
		for (int i = 0; i < M; i++) {
			horPos;
			cin >> horPos;
			cowIndex = bs(horPos);
			if (0 <= cowIndex && cowIndex < N) {
				int cP = cowPos[cowIndex];
				int diff = abs(cP - horPos);
				if (mini > diff) {
					mini = diff;
					cnt = 1;
				}
				else if (mini == diff) {
					cnt++;
				}
			}
			if (0 < cowIndex && cowIndex < N && cowPos[cowIndex] != horPos) {
				int cP = cowPos[cowIndex - 1];
				int diff = abs(cP - horPos);
				if (mini > diff) {
					mini = diff;
					cnt = 1;
				}
				else if (mini == diff) {
					cnt++;
				}
			}
		}
		cout << "#" << test_case << " " << (num + mini) << " " << cnt <<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}