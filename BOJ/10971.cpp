#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;
vector<int>v;
vector<vector<int>>w;
vector<int>t;
int main(void) {
    int N, temp;
    cin >> N;
    int MIN = 11000000;
    int path = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            cin >> temp;
            t.push_back(temp);
        }
        w.push_back(t);
        t.clear();
    }
    for (int i = 0; i < N; i++) {
        v.push_back(i);
    }
    do {
        for (int i = 0; i < N-1; i++) {
            if (w[v[i]][v[i + 1]] != 0) {
                path += w[v[i]][v[i + 1]];
            }
            else {
                path = 11000000;
            }
        }
        if (w[v[N - 1]][v[0]] != 0) {
            path += w[v[N - 1]][v[0]];
        }
        else {
            path = 11000000;
        }
        if (MIN > path) {
            MIN = path;
        }
        path = 0;
    } while (next_permutation(v.begin(), v.end()));
    cout << MIN;
    return 0;
}