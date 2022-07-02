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
int N, K;

int main() {
    cin >> N >> K;
    int low = 1;
    int high = N * N;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }
        if (cnt < K) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low;
    return 0;
}