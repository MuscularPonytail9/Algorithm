#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    long long sum = 0;
    long long sum1 = 0;
    long long sum2 = 0;
    for (int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
    }
    for (int i = 0; i < queue2.size(); i++) {
        sum2 += queue2[i];
    }
    long long hSum = (sum1 + sum2) / 2;
    int cnt = 0;
    bool isPossible = true;
    while (true) {
        if (sum1 == hSum) {
            break;
        }
        if (cnt > 240000) {
            isPossible = false;
            break;
        }
        cnt++;
        if (sum1 < hSum) {
            int ele2 = queue2.front();
            sum2 -= ele2;
            sum1 += ele2;
            queue1.push_back(ele2);
            queue2.erase(queue2.begin());
        }
        else {
            int ele1 = queue1.front();
            sum1 -= ele1;
            sum2 += ele1;
            queue2.push_back(ele1);
            queue1.erase(queue1.begin());
        }

    }
    if (isPossible == true) {
        answer = cnt;
    }
    return answer;
}