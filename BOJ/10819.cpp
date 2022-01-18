#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;
vector<int>v;

int main(void) {
	int N, temp;
	int MAX = 0;
	cin >> N;
	int current = 0;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	do {
		for (int i = 0; i < N - 1; i++) {
			current += abs(v[i + 1] - v[i]);
		}
		if (MAX < current) {
			MAX = current;
		}
		current = 0;
	} while (next_permutation(v.begin(), v.end()));
	cout << MAX << '\n';
}