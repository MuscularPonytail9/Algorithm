#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>
#include <cmath>
#include <utility>
#include <cstdio>
using namespace std;

bool comp(pair<char, int> ic1, pair<char, int> ic2) {
    return ic1.second > ic2.second;
}

vector<string>v;
vector<pair<char,int>>arr;
map<char,int> m;
int main(void) {
    int N;
    int sum = 0;
    string temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    for (auto k : v) {
        for (int i = 0; i < k.size(); i++) {
            m[k[i]] += pow(10,(k.size()-1-i));
        }
    }
    for (auto k : m) {
        arr.push_back({ k.first, k.second });
    }
    m.clear();
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < arr.size(); i++) {
        arr[i].second = 9 - i;
    }
    for (auto k : arr) {
        m[k.first] = k.second;
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            sum = sum + pow(10, (v[i].size() - 1 - j)) * m[v[i][j]];
        }
    }
    cout << sum;
    return 0;
}