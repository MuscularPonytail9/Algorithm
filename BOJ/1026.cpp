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

int N;
vector<int> A;
vector<int> B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		B.push_back(temp);
	}

	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());
	int s = 0;
	for (int i = 0; i < N; i++) {
		s += A[i] * B[i];
	}

	cout << s;

	return 0;
}