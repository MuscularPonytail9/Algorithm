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
int L, C, num1, num2, li;
char temp;
vector<char> v;
vector<char> result;
bool visited[15];
bool isM(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    else {
        return false;
    }
}

void dfs(int current) {
    if (result.size() == L) {
        if (num1 >= 1 && num2 >= 2) {
            for (int i = 0; i < L; i++) {
                cout << result[i];
            }
            cout << '\n';
        }
    }
    else {
        for (int i = current; i < C; i++) {
            if (visited[i] == false) {
                result.push_back(v[i]);
                /*for (int j = 0; j < result.size(); j++) {
                    cout << result[j];
                }
                cout << '\n';*/
                if (isM(v[i]) == true) {
                    num1++;
                }
                else {
                    num2++;
                }
                visited[i] = true;
                dfs(i + 1);
                visited[i] = false;
                if (isM(v[i]) == true) {
                    num1--;
                }
                else {
                    num2--;
                }
                result.pop_back();
                /*for (int j = 0; j < result.size(); j++) {
                    cout << result[j];
                }
                cout << '\n';*/
            }
        }
    }
}

int main() {
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    //a c i s t w
    sort(v.begin(), v.end());
    dfs(0);
    return 0;
}