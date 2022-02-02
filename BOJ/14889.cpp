#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;
vector<int>a;
vector<int>b;
vector<int>v;
vector<int>mask;
vector<int>t;
vector<vector<int>>w;
int main(void) {
    int aTeamStat = 0;
    int bTeamStat = 0;
    int diff = 0;
    int MIN = 10000000000;
    int N, temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            t.push_back(temp);
        }
        w.push_back(t);
        t.clear();
    }
    for (int i = N; i >= 1; i--) {
        v.push_back(i);
    }
    for (int i = 0; i < N/2; i++) {
        mask.push_back(1);
    }
    for (int i = 0; i < N - N/2; i++) {
        mask.push_back(0);
    }

    sort(mask.begin(), mask.end());

    do {
        for (int i = 0; i < N; i++) {
            if (mask[i] == 1) {
                a.push_back(v[i]);
            }
            else {
                b.push_back(v[i]);
            }
        }
        for (int j = 0; j < N / 2; j++) {
            for (int k = j + 1; k < N / 2; k++) {
                aTeamStat += w[a[j]-1][a[k]-1];
                aTeamStat += w[a[k]-1][a[j]-1];
            }
        }
        for (int j = 0; j < N / 2; j++) {
            for (int k = j + 1; k < N / 2; k++) {
                bTeamStat += w[b[j]-1][b[k]-1];
                bTeamStat += w[b[k]-1][b[j]-1];
            }
        }
        diff = abs(aTeamStat - bTeamStat);
        if (diff < MIN) {
            MIN = diff;
        }
        a.clear();
        b.clear();
        aTeamStat = 0;
        bTeamStat = 0;
    } while (next_permutation(mask.begin(), mask.end()));
    cout << MIN;
    mask.clear();
    return 0;
}