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
bool isEmpty;
int N, m, classRoom, result;
set<int> nums;
map<int, int> S;
map<int, int> F;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        nums.insert(temp);
        S[temp]++;
        cin >> temp;
        nums.insert(temp);
        m = max(m, temp);
        F[temp]++;
    }
    for (auto t : nums) {
        classRoom = classRoom + S[t] - F[t];
        result = max(result, classRoom);
    }
    cout << result;

    return 0;
}
