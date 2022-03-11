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
int dp[1002];
int main(void) {
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;
	for (int i = 5; i <= N; i++) {
			dp[i] = (dp[i-1] + dp[i - 2]) % 10007;
	}
	cout << dp[N] % 10007;
	return 0;
}