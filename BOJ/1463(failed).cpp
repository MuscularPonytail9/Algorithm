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


int N;
int cnt;
int num = 1;
void makeOne() {
    if (num == N) {
        cout << cnt;
        return;
    }
    if (num * 3 <= N) {
        num = num * 3;
        cnt++;
        makeOne();
    }
    else if (num * 2 <= N) {
        num = num * 2;
        cnt++;
        makeOne();
    }
    else {
        num = num + 1;
        cnt++;
        makeOne();
    }
}

int main() {
    cin >> N;
    makeOne();
    return 0;
}