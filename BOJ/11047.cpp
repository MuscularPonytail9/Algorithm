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

int N, K;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.rbegin(), v.rend());
	int res = 0;
	while (K != 0) {
		for (int i = 0; i < v.size(); i++) {
			if (K < v[i]) {
				continue;
			}
			int cnt = K / v[i];
			res += cnt;
			K -= cnt * v[i];
		}
	}
	cout << res;

	return 0;
}