#include <iostream>

/*
 * [245] 백준 1003번 피보나치 함수
 */

using namespace std;

#define MAX 40

pair<int, int> dp[MAX];

int main() {
    int T, N;
    cin >> T;
    dp[0] = { 1, 0 };
    dp[1] = { 0, 1 };

    for (int i = 2; i <= MAX; ++i) {
        dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
    }

    while (T--) {
        cin >> N;
        cout << dp[N].first << " " << dp[N].second << "\n";
    }
    return 0;
}