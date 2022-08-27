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

string arr[500];
string ans;
int N, idx;


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
		cin >> N;
		N--;
		string s;
		cin >> s;
		idx = 0;
		for (int i = 0; i < s.length(); i++) {
			string temp = "";
			for (int j = i; j < s.length(); j++) {
				temp = temp + s[j];
			}
			arr[idx++] = temp;
		}
		sort(arr, arr + idx);
		if (N >= idx) {
			ans = "none";
		}
		else {
			ans = arr[N];
		}
		cout << "#" << test_case << " " << ans <<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}