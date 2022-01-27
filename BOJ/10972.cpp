#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;
vector<int>v;

int main(void) {
    int N, temp;
    cin >> N;
    int current = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    if (next_permutation(v.begin(), v.end())) {
        for (int i = 0; i < N; i++) {
            cout << v[i] << ' ';
        }
    }
    else {
        cout << -1;
    }
    return 0;
}