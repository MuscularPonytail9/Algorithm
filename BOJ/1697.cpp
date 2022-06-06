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

using namespace std;
int N, K, cur;
int num;
bool visited[200001];

void BFS() {
    queue<pair<int, int>> q;
    q.push({ N, 0 });
    visited[N] = true;
    while (q.empty() == false) {
        auto P = q.front();
        q.pop();
        cur = P.first;
        num = P.second;
        //cout << cur << "," << num << " poped" <<'\n';
        if (cur == K) {
            //cout << cur << "      " << num << '\n';
            cout << num;
            break;
        }
        if (visited[cur + 1] == false && cur + 1 <= 100000) {
            q.push({ cur + 1, num + 1 });
            visited[cur + 1] = true;
            //cout << cur + 1 << "," << num + 1 << " pushed" << '\n';
        }
        if (cur - 1 <= 100000 && cur - 1 >= 0) {
            if (visited[cur - 1] == false) {
                q.push({ cur - 1, num + 1 });
                visited[cur - 1] = true;
            }
            
            //cout << cur - 1 << "," << num + 1 << " pushed" << '\n';
        }
        if (cur * 2 < K + 2 && cur * 2 <= 100000) {
            if (visited[cur * 2] == false) {
                q.push({ cur * 2, num + 1 });
                visited[cur * 2] = true;
            }
            
            //cout << cur * 2 << "," << num + 1 << " pushed" << '\n';
        }
    }
}

int main() {
    cin >> N >> K;
    BFS();
    return 0;
}
