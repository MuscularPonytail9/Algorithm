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
		int N;
		long long M;
		cin >> N >> M;
		long long mini = 1;
		long long maxi = 1;
		long long arr[100] = {0};
		for (int i = 0; i < N; i++) {
			long long temp;
			cin >> temp;
			arr[i] = temp;
			if (temp > maxi) {
				maxi = temp;
			}
		}
		while (mini <= maxi) {
			long long mid = (mini + maxi) / 2;
			long long cnt = 0;
			for (int j = 0; j < N; j++) {
				cnt += arr[j] / mid;
			}
			if (cnt < M) {
				maxi = mid - 1;
			}
			else {
				mini = mid + 1;
			}
		}
		cout << "#" << test_case << " " << maxi << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}