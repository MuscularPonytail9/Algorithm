#include <unordered_map>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <cstdio>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int cnt = 0;
		vector<pair<int, int>> p;
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			int temp1, temp2;
			cin >> temp1 >> temp2;
			p.push_back({ temp1, temp2 });
		}
		sort(p.begin(), p.end());
		int temp = 0;
		int res = 1;
		for (int i = 1; i < p.size(); i++) {
			if (p[temp].second > p[i].second) {
				res++;
				temp = i;
			}
		}
		cout << res << '\n';
	}
	return 0;
}