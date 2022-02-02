#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;
vector<int>v;
vector<int>calc;
vector<int>calcNum;
vector<int>mask;
int main(void) {
    int N, temp;
    int current = 0;
    int MAX = -1000000000;
    int MIN = 1000000000;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < 4; i++) {
        cin >> temp;
        calcNum.push_back(temp);
    }
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < calcNum[i]; k++) {
            calc.push_back(i);
        }
    }
    current = v[0];
    do {
        for (int i = 0; i < N - 1; i++) {
            if (calc[i] == 0) {
                current = current + v[i + 1];
            }
            else if (calc[i] == 1) {
                current = current - v[i + 1];
            }
            else if (calc[i] == 2) {
                current = current * v[i + 1];
            }
            else if (calc[i] == 3) {
                current = current / v[i + 1];
            }
        }
        if (current < MIN) {
            MIN = current;
        }
        if (current > MAX) {
            MAX = current;
        }
        current = v[0];
    } while (next_permutation(calc.begin(), calc.end()));
    cout << MAX << '\n' << MIN;

    
    return 0;
}