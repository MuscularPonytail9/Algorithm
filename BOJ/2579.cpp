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
int dp[302];
int stair[302];
int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}
	dp[0] = 0;
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(stair[i] + dp[i - 2], dp[i - 3] + stair[i] + stair[i-1]);
	cout << dp[N];
	return 0;
}