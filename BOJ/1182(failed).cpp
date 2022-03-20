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
bool v[21];
void bt(int index) {
	cout << "index is " << index << '\n';
	if (index >= N) {
		return;
	}
	if (isFirst == true) {
		isFirst = false;
		v[index] = true;
		sum += sy[index];
		cout << sum << '\n';
		if (sum == S) {
			cnt++;
			cout << "cnt++" << '\n';
		}
		bt(index + 1);
		v[index] = false;
	}
	else {
		v[index] = true;
		sum += sy[index];
		cout << sum << '\n';
		if (sum == S) {
			cnt++;
			cout << "cnt++" << '\n';
		}
		
		bt(index + 1);
		v[index] = false;
	}
}

int main(void) {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> sy[i];
	}
	for (int i = 0; i < N; i++) {
		cout << "bt(" << i << ") started" << '\n';
		bt(i);
		sum = 0;
		isFirst = true;
	}
	cout << cnt;
	return 0;
}