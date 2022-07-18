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
#define INF 9999999
using namespace std;
int n, m, k, x;
vector<pair<int, int>> v[300001];

void dijkstra() {
    vector<int> dist(n + 1, INF); // 처음에 INF로 초기화
    priority_queue<pair<int, int>> pq; // (cost, cur)

    dist[x] = 0;
    pq.push({ 0, x });

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first; // 다음 노드
            int ncost = cost + v[cur][i].second; // 다음 노드까지의 가중치

            if (ncost < dist[next]) { // 더 작은 값을 구한 경우
                dist[next] = ncost; // 값 갱신
                pq.push({ -ncost, next }); // pq에 삽입
            }
        }
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            flag = false;
            cout << i << endl;
        }
    }
    if (flag) // 최단거리가 k인 도시가 없는 경우 -1 출력
        cout << -1;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &x);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back({ y, 1 }); // cost는 전부 1
    }

    dijkstra();
}