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
int dp[1000002];
int main(void) {
	cin >> N;
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 3;
	for (int i = 6; i <= N; i++) {
		if (i % 3 != 0 && i % 2 != 0) {
			dp[i] = dp[i - 1] + 1;
		}
		else if (i % 6 == 0) {
			dp[i] = min(dp[i / 3], dp[i / 2]) + 1;
		}
		else if (i % 3 == 0) {
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		}
		
	}
	cout << dp[N];
	return 0;
}