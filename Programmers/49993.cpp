#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        int ssIdx = 0;
        bool isOK = true;
        for (int j = 0; j < skill_trees[i].size(); j++) {
            for (int k = 0; k < skill.size(); k++) {
                if (skill_trees[i][j] == skill[k]) {
                    if (k == ssIdx) {
                        ssIdx++;
                        break;
                    }
                    else {
                        isOK = false;
                    }
                }
            }
        }
        if (isOK == true) {
            answer++;
        }
    }
    return answer;
}