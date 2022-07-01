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
int N, M, temp;
map<int, int> c;
vector<int> j;
vector<int> result;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        c[temp]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        j.push_back(temp);
    }
    for (int i = 0; i < M; i++) {
        auto k = c.find(j[i]);
        if (k != c.end()) {
            result.push_back(k->second);
        }
        else {
            result.push_back(0);
        }
    }
    for (auto k : result) {
        cout << k << " ";
    }
    return 0;
}
