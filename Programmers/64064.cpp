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

int answer = 0;
vector<vector<string>> v;
vector<string> cal;
set<vector<string>> s;

void DFS(int i) {
	if (i > v.size() - 1) {
		vector<string> temp = cal;
		sort(temp.begin(), temp.end());
		s.insert(temp);
	}
	else {
		for (int idx = 0; idx < v[i].size(); idx++) {
			if (find(cal.begin(), cal.end(), v[i][idx]) == cal.end()) {
				cal.push_back(v[i][idx]);
				DFS(i + 1);
				cal.pop_back();
			}
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	for (int idx1 = 0; idx1 < banned_id.size(); idx1++) {
		vector<string> v1;
		for (int idx2 = 0; idx2 < user_id.size(); idx2++) {
			bool isSame = true;
			for (int i = 0; i < banned_id[idx1].size(); i++) {
				if (banned_id[idx1].size() == user_id[idx2].size() && (banned_id[idx1][i] == '*' || banned_id[idx1][i] == user_id[idx2][i])) {

				}
				else {
					isSame = false;
					break;
				}
			}
			if (isSame == true) {
				v1.push_back(user_id[idx2]);
			}
		}
		v.push_back(v1);
	}
	DFS(0);
	answer = s.size();
	return answer;
}

int main() {
	int N, K;
	cin >> N >> K;
	vector<string> v1;
	vector<string> v2;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		v1.push_back(temp);
	}
	for (int i = 0; i < K; i++) {
		string temp;
		cin >> temp;
		v2.push_back(temp);
	}
	solution(v1, v2);
	cout << answer;
	return 0;
}