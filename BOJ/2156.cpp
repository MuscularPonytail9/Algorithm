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
int N;
int dp[10002];
int wine[10002];
bool isTriple = false;
int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> wine[i];
	}
	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(wine[i] + dp[i - 2], dp[i - 3] + wine[i] + wine[i-1]);
		if (dp[i] < dp[i - 1]) {
			dp[i] = dp[i - 1];
		}
	}
	/*for (int i = 1; i <= N; i++) {
		cout << wine[i] << " " << dp[i] << '\n';
	}*/
	cout << dp[N];
	return 0;
}