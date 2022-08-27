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

int W[200000], S[200000];
int N, K;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("sample_input.txt", "r", stdin);
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> W[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> S[i];
		}
		int low = 0;
		int high = 200000;
		while (low < high) {
			bool check = false;
			int mid = (low + high) / 2;
			int num = -1;
			for (int i = 0; i < K; i++) {
				for (int j = 0; j < S[i]; j++) {
					num++;
					if (num == N) {
						low = mid + 1;
						check = true;
					}
					if (W[num] > mid) {
						i--;
						break;
					}
				}
			}
			if (check == false) {
				high = mid;
			}
		}
		cout << "#" << test_case << " " << high << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}