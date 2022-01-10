#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> v1(N);
	vector<string> v2(M);
	vector<string> v3;
	for (int i = 0; i < N; i++) {
		cin >> v1[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> v2[i];
	}

	map<string, int> m;
	int num = 0;
	for (auto t : v1) {
		m[t]++;
	}
	for (auto t : v2) {
		m[t]++;
	}
	for (auto t : m) {
		if (t.second == 2) {
			num++;
			v3.push_back(t.first);
		}
	}
	cout << num << "\n";
	for (auto t : v3) {
		cout << t << "\n";
	}

	return 0;
}