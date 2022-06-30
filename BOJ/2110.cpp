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
int N, C, maximum, minimum, mid, num, result;
int temp;
vector<int> v;

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    minimum = 1;
    maximum = v[N - 1];

    while (maximum >= minimum) {
        mid = (minimum + maximum) / 2;
        //cout << minimum << " " << mid << " " << maximum << '\n';
        num = 1;
        int cur = 0;
        for (int i = 0; i < N; i++) {
            if (v[i] - v[cur] >= mid) {
                num++;
                cur = i;
            }
        }
        //cout << "num " << num << '\n';
        if (num >= C) {
            result = mid;
            minimum = mid + 1;
        }
        else {
            maximum = mid - 1;
        }
    }
    cout << result;

    return 0;
}