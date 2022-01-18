#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;
bool isNumber(const string& str) {
	for (char const& c : str) {
		if (isdigit(c) == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	vector<string> v;
	vector<string> v2;
	string tmp;
	int N, M;
	int pokeNum;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		v2.push_back(tmp);
	}
	for (int i = 0; i < M; i++) {
		if (isNumber(v2[i]) == true) {
			pokeNum = stoi(v2[i]);
			cout << v[pokeNum - 1] << '\n';
		}
		else {
			auto it = find(v.begin(), v.end(), v2[i]);
			cout << it - v.begin() + 1 << '\n';
		}
	}
	return 0;
}