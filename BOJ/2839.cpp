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
bool isSucc;

void sb() {
    int fiveBag = N / 5;
    for (int i = fiveBag; i >= 0; i--) {
        for (int j = 0; j <= (N - (i * 5))/3 + 1; j++) {
            //cout << "5kg은 " << i << ", 3kg은 " << j << '\n';
            if(N == i * 5 + j * 3 && isSucc == false) {
                cout << i + j << '\n';
                isSucc = true;
                break;
            }
        }
    }
}

int main() {
    cin >> N;
    sb();
    if (isSucc == false) {
        cout << -1;
    }
    return 0;
}