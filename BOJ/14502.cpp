#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int m[9][9];
bool visited[9][9];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int maxi = 0;
vector<pair<int, int>> v;

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int temp;
            cin >> temp;
            if (temp == 0) {
                v.push_back({ i, j });
            }
            m[i][j] = temp;
        }
    }
    for (int fir = 0; fir < v.size() - 2; fir++) {
        for (int sec = fir + 1; sec < v.size() - 1; sec++) {
            for (int thi = sec + 1; thi < v.size(); thi++) {
                int tempm[9][9];
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        tempm[i][j] = m[i][j];
                    }
                }
                tempm[v[fir].first][v[fir].second] = 1;
                tempm[v[sec].first][v[sec].second] = 1;
                tempm[v[thi].first][v[thi].second] = 1;
                for (int i = 1; i <= M; i++) {
                    for (int j = 1; j <= N; j++) {
                        if (tempm[i][j] != 2 || visited[i][j] == true) {
                            continue;
                        }
                        queue<pair<int, int>> q;
                        q.push({ i, j });
                        while (q.empty() == false) {
                            auto cur = q.front();
                            int cx = cur.first;
                            int cy = cur.second;
                            tempm[cx][cy] = 2;
                            visited[cx][cy] = true;
                            q.pop();
                            for (int k = 0; k < 4; k++) {
                                int nx = cx + dx[k];
                                int ny = cy + dy[k];
                                if (tempm[nx][ny] == 1 || visited[nx][ny] == true || nx < 1 || nx > M || ny < 1 || ny > N) {
                                    continue;
                                }
                                q.push({ nx, ny });
                            }
                            for (int p = 1; p <= N; p++) {
                                for (int o = 1; o <= M; o++) {
                                    cout << tempm[o][p] << " ";
                                }
                                cout << '\n';
                            }
                            cout << '\n';
                        }
                    }
                }
                int cnt = 0;
                for (int i = 1; i <= M; i++) {
                    for (int j = 1; j <= N; j++) {
                        if (tempm[i][j] == 0) {
                            cnt++;
                        }
                    }
                }
                cout << cnt << '\n';
                if (maxi < cnt) {
                    maxi = cnt;
                }
            }
        }
    }
    cout << maxi;
    return 0;
}