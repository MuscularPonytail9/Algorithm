#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> s;
    vector<string> v;
    for (auto t : phone_book) {
        s.insert(t);
    }
    for (auto t : s) {
        v.push_back(t);
    }
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i + 1].find(v[i]) == 0) {
            answer = false;
        }
    }
    return answer;
}