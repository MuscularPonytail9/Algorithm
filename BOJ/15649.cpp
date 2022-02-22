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

int N, M;
int arr[9];
bool visit[9];
void bt(int num) {
    if (num == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!visit[i]) {
            visit[i] = true;
            arr[num] = i;
            bt(num + 1);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    bt(0);
    return 0;
}