#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAXN = 10; // 최대 노드 수
const int MAXMASK = 1 << MAXN; // 비트마스크 최대값

int n;
int map[MAXN][MAXN][MAXN]; // [subway][i][j] 구조
int dp[MAXMASK][MAXMASK][2]; // [현재노드][비트마스크][최대/최소]
int bitmasking; // 모든 노드를 방문하는 비트마스크 값
int min_cost, max_cost;

// DFS 탐색
void dfs(int visited, int subway, int nowNode) {
    if (visited == bitmasking) {
        for (int i = 0; i < n; i++) {
            int move = 1 << i;
            if (subway & move) continue;
            if (map[i][nowNode][0] == 0) continue;

            int costMax = dp[visited][subway][0] + map[i][nowNode][0];
            int costMin = dp[visited][subway][1] + map[i][nowNode][0];

            if (dp[bitmasking][subway | move][0] == -1) {
                dp[bitmasking][subway | move][0] = costMax;
            } else if (dp[bitmasking][subway | move][0] < costMax) {
                dp[bitmasking][subway | move][0] = costMax;
            }
            if (dp[bitmasking][subway | move][1] == INF) {
                dp[bitmasking][subway | move][1] = costMin;
            } else if (dp[bitmasking][subway | move][1] > costMin) {
                dp[bitmasking][subway | move][1] = costMin;
            }
        }
        return;
    }

    for (int i = 1; i < n; i++) {
        int node = 1 << i;
        if (visited & node) continue;

        for (int j = 0; j < n; j++) {
            int sub = 1 << j;
            if (subway & sub) continue;
            if (map[j][nowNode][i] == 0) continue;

            int nextVisited = visited | node;
            int nextSubway = subway | sub;

            int costMin = dp[visited][subway][1] + map[j][nowNode][i];
            int costMax = dp[visited][subway][0] + map[j][nowNode][i];

            if (dp[nextVisited][nextSubway][1] > costMin) {
                dp[nextVisited][nextSubway][1] = costMin;
                dfs(nextVisited, nextSubway, i);
            }

            if (dp[nextVisited][nextSubway][0] < costMax) {
                dp[nextVisited][nextSubway][0] = costMax;
                dfs(nextVisited, nextSubway, i);
            }
        }
    }
}

int main() {
    int test_case_count;
    scanf("%d", &test_case_count);

    for (int test_case = 0; test_case < test_case_count; ++test_case) {
        scanf("%d", &n);

        bitmasking = (1 << n) - 1;

        for (int i = 0; i < MAXMASK; i++) {
            for (int j = 0; j < MAXMASK; j++) {
                dp[i][j][1] = INF;
                dp[i][j][0] = -1;
            }
        }

        for (int subway = 0; subway < n; subway++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    scanf("%d", &map[subway][i][j]);
                }
            }
        }

        dp[0][0][0] = 0; // 시작 지점에서의 초기값 설정
        dp[0][0][1] = 0; // 시작 지점에서의 초기값 설정

        dfs(0, 0, 0);

        min_cost = dp[bitmasking][bitmasking][1];
        max_cost = dp[bitmasking][bitmasking][0];

        if (min_cost == INF) min_cost = 0;
        if (max_cost == -1) max_cost = 0;

        printf("%d %d\n", min_cost, max_cost);
    }

    return 0;
}
