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
#include <map>
#include <functional>
#include <time.h>

using namespace std;
int T, temp, temp2;
vector<int> result;
void DP(int payload) {
    vector<int> v1;
    vector<int> v2;
    int dp[100000];
    int nextPos[100000];
    for (int i = 0; i < payload; i++) {
        cin >> temp2;
        v1.push_back(temp2);
    }
    for (int i = 0; i < payload; i++) {
        cin >> temp2;
        v2.push_back(temp2);
    }
    vector<vector<int>> v;
    v.push_back(v1);
    v.push_back(v2);
    if (v[0][0] >= v[1][0]) {
        dp[0] = v[0][0];
    }
    else {
        dp[0] = v[1][0];
    }
    if (payload == 1) {
        result.push_back(dp[0]);
        return;
    }
    if (v[0][0] + v[1][1] >= v[0][1] + v[1][0]) {
        dp[1] = v[0][0] + v[1][1];
        nextPos[1] = 0;
    }
    else {
        dp[1] = v[0][1] + v[1][0];
        nextPos[1] = 1;
    }
    if (payload == 2) {
        result.push_back(dp[1]);
        return;
    }
    for (int i = 2; i < payload; i++) {
        dp[i] = dp[i - 1] + v[nextPos[i - 1]][i];
        if (nextPos[i - 1] == 0) {
            nextPos[i] = 1;
        }
        else {
            nextPos[i] = 0;
        }
        if (dp[i] < dp[i - 2] + max(v[0][i], v[1][i])) {
            dp[i] = dp[i - 2] + max(v[0][i], v[1][i]);
            if (v[0][i] > v[1][i]) {
                nextPos[i] = 1;
            }
            else {
                nextPos[i] = 0;
            }
        }
    }
    result.push_back(dp[payload - 1]);
}
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> temp;
        DP(temp);
    }
    for (int i = 0; i < T; i++) {
        cout << result[i] << '\n';
    }
    return 0;
        //반례
        //1
        //6
        //20 5 30 9 19 0
        //30 9 10 0 30 14
        //output:90
        //answer : 92
}