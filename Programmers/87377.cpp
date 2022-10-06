#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<pair<long long, long long>> s;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    long long minX = 9223372036854775807;
    long long minY = 9223372036854775807;
    long long maxX = -9223372036854775808;
    long long maxY = -9223372036854775808;
    for (int i = 0; i < line.size(); i++) {
        for (int j = i + 1; j < line.size(); j++) {
            if ((long long)line[i][0] * (long long)line[j][1] - (long long)line[i][1] * (long long)line[j][0] == 0) {
                continue;
            }
            double x1 = (double)((long long)line[i][1] * (long long)line[j][2] - (long long)line[i][2] * (long long)line[j][1]) / (double)((long long)line[i][0] * (long long)line[j][1] - (long long)line[i][1] * (long long)line[j][0]);
            double y1 = (double)((long long)line[i][2] * (long long)line[j][0] - (long long)line[i][0] * (long long)line[j][2]) / (double)((long long)line[i][0] * (long long)line[j][1] - (long long)line[i][1] * (long long)line[j][0]);
            if ((x1 - (long long)x1 == 0) && (y1 - (long long)y1 == 0)) {
                long long x = (long long)x1;
                long long y = (long long)y1;
                s.insert({ x, y });
                minX = min(minX, x);
                maxX = max(maxX, x);
                minY = min(minY, y);
                maxY = max(maxY, y);
            }
        }
    }
    for (long long j = maxY; j >= minY; j--) {
        string temp = "";
        for (long long i = minX; i <= maxX; i++) {
            auto t = s.find({ i,j });
            if (t == s.end()) {
                temp += ".";
            }
            else {
                temp += "*";
                s.erase(t);
            }
        }
        answer.push_back(temp);
    }
    return answer;
}