#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <string> 
#include <cmath>
#include <cstdio>
#include <set>

using namespace std;

int N, S;
int sy[21];
int sum;
int cnt;
bool isFirst = true;
//vector<int> v;
void bt(int index) {
	//cout << "index is " << index << '\n';
	if (index >= N) {
		return;
	}
	if (isFirst == true) {
		isFirst = false;
		sum += sy[index];
		//v.push_back(sy[index]);
		/*for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';*/
		if (sum == S) {
			cnt++;
			//cout << "cnt++" << '\n';
		}
		bt(index + 1);
		sum -= sy[index];
		//v.pop_back();
		bt(index + 1);
	}
	else {
		sum += sy[index];
		//v.push_back(sy[index]);
		/*for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}*/
		//cout << "        " << sum <<'\n';
		if (sum == S) {
			cnt++;
			//cout << "cnt++" << '\n';
		}
		bt(index + 1);
		sum -= sy[index];
		//v.pop_back();
		bt(index + 1);
	}
}

int main(void) {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> sy[i];
	}
	bt(0);
	cout << cnt;
	return 0;
}