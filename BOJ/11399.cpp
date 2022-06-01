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

using namespace std;
int N, result;
vector<int> v;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        result += v[i] * (v.size() - i);
    }
    cout << result;

    return 0;
}
