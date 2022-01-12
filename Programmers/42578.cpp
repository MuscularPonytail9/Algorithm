#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for (auto t : clothes) {
        m[t[1]]++;
    }
    for (auto t : m) {
        answer *= (t.second + 1);
    }
    answer--;
    return answer;
}