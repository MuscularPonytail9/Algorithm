#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;
int num, N, payload, result;
vector<int> v;
vector<int> v2;

bool isSorted() {
	bool check = true;
	for (int l = 0; l < N - 1; l++) {
		if (v[l] > v[l + 1]) {
			check = false;
			break;
		}
	}
	return check;
}
void function() {
	for (int k = 0; k < N - 1; k = k + 2) {
		if (v[k] > v[k + 1]) {
			int temp = v[k + 1];
			v[k + 1] = v[k];
			v[k] = temp;
		}
	}
	for (int k = 1; k < N - 1; k = k + 2) {
		if (v[k] > v[k + 1]) {
			int temp = v[k + 1];
			v[k + 1] = v[k];
			v[k] = temp;
		}
	}
}

int main(void) {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> payload;
			v.push_back(payload);
		}
		while (isSorted() == false) {
			function();
			result++;
		}
		v2.push_back(result);
		result = 0;
		v.clear();
	}
	for (int i = 0; i < v2.size(); i++) {
		cout << "#" << i + 1 << " " << v2[i] << '\n';
	}
	return 0;
}