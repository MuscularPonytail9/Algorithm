#ifndef _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#endif
#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <array>
#include <string>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    int res = 0;
    if (pq.size() == 1) {
        cout << res << '\n';
    }
    else if (pq.size() == 2) {
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        res = num1 + num2;
    }
    else {
        while (true) {
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            int sum = num1 + num2;
            res = res + sum;
            if (pq.empty()) {
                break;
            }
            else {
                pq.push(sum);
            }
        }
        cout << res << '\n';
    }
    return 0;
}