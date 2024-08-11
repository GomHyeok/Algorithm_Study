#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <queue>

#define MAXCOST 987654321

using namespace std;

int n, min_cost, max_cost;
int bitmasking = 1;
vector<vector<vector<int> > > map;
int check_subway[10];
int check_node[10];

//refactor
int checkSubway = 0;
int checkNode = 0;
int dp[256][256][2];

void dfs(int now, int subway, int nowNode) {
    if(now == bitmasking-1) {
        int move = bitmasking - subway;
        int cnt = 0;

        if(subway & move) return;

        while(move != 1) {
            move /= 2;
            cnt++;
        }

        if(map[cnt][nowNode][0] == 0) return;

        int costMax = dp[now][subway][0] + map[cnt][nowNode][0];
        int costMin = dp[now][subway][1] + map[cnt][nowNode][0];

        if(dp[bitmasking][bitmasking][0] == -1) {
            dp[bitmasking][bitmasking][0] = costMax; 
        } else if(dp[bitmasking][bitmasking][0] < costMax) {
            dp[bitmasking][bitmasking][0] = costMax; 
        }
        if(dp[bitmasking][bitmasking][1] == MAXCOST) {
            dp[bitmasking][bitmasking][1] = costMin; 
        } else if(dp[bitmasking][bitmasking][1] > costMin) {
            dp[bitmasking][bitmasking][1] = costMin; 
        }
        return;
    }

    for(int i=1; i<n; i++) {
        int node = 1 << i;
        int nextNode = now | node;
        if(now & node) continue;
        for(int j=0; j<n; j++) {
            bool flag = true;
            int sub = 1 << j;
            int nextSub = subway | sub;

            if(subway & sub) continue;
            if(map[j][nowNode][i] == 0) continue;

            int nowMin = dp[nextNode][nextSub][1];
            int nowMax = dp[nextNode][nextSub][0];

            int nextMin = dp[now][subway][1] + map[j][nowNode][i];
            int nextMax = dp[now][subway][0] + map[j][nowNode][i];

            if(nowNode == 0) {
                nextMin =  map[j][nowNode][i];
                nextMax =  map[j][nowNode][i];
            }
            
            if(nowMin > nextMin) {
                dp[nextNode][nextSub][1] = nextMin;
                flag = false;
            }

            if(nowMax < nextMax) {
                dp[nextNode][nextSub][0] = nextMax;
                flag = false;
            }

            if(!flag) {
                dfs(nextNode, nextSub, i);
            }

        }
    }
}

void dfs2(int now, int subway, int nowNode) {
    if (now == bitmasking-1) {
        // 모든 노드를 방문했을 때, 0번 노드로 돌아가는 비용을 계산
        for (int i = 0; i < n; i++) {
            int move = 1 << i;
            if (subway & move) continue;
            if (map[i][nowNode][0] == 0) continue; // 경로가 없을 경우

            cout<<move<<endl;

            int costMax = dp[now][subway][0] + map[i][nowNode][0];
            int costMin = dp[now][subway][1] + map[i][nowNode][0];

            if (dp[now+1][subway | move][0] == -1) {
                dp[now+1][subway | move][0] = costMax;
            } else if (dp[now+1][subway | move][0] < costMax) {
                dp[now+1][subway | move][0] = costMax;
            }
            if (dp[now+1][subway | move][1] == MAXCOST) {
                dp[now+1][subway | move][1] = costMin;
            } else if (dp[now+1][subway | move][1] > costMin) {
                dp[now+1][subway | move][1] = costMin;
            }
        }
        return;
    }

    for (int i = 1; i < n; i++) {
        int node = 1 << i;
        if (now & node) continue; // 이미 방문한 노드면 건너뛰기

        for (int j = 0; j < n; j++) {
            int sub = 1 << j;
            if (subway & sub) continue; // 이미 사용한 이동수단이면 건너뛰기
            if (map[j][nowNode][i] == 0) continue; // 경로가 없을 경우

            int nextNode = now | node;
            int nextSub = subway | sub;

            int nextMin = dp[now][subway][1] + map[j][nowNode][i];
            int nextMax = dp[now][subway][0] + map[j][nowNode][i];

            if (nowNode == 0) {
                nextMin = map[j][nowNode][i];
                nextMax = map[j][nowNode][i];
            }

            bool flag = false;

            if (dp[nextNode][nextSub][1] > nextMin) {
                dp[nextNode][nextSub][1] = nextMin;
                flag = true;
            }

            if (dp[nextNode][nextSub][0] < nextMax) {
                dp[nextNode][nextSub][0] = nextMax;
                flag = true;
            }

            if (flag) {
                dfs2(nextNode, nextSub, i);
                // 재귀 호출 후 경로 및 이동 수단 제거 (백트래킹)
            }
        }
    }
}

int main(){
    int test_case_count;
    //cin >> test_case_count;

    scanf("%d", &test_case_count);

    for(int test_case = 0; test_case < test_case_count; ++test_case) {
        //cin >> n;
        bitmasking = 1;
        scanf("%d", &n);

        for(int i=0; i<n; i++) {
            int move = 1 << i;
            bitmasking |= move;
        }

        for(int i=0; i<256; i++) {
            for(int j=0; j<256; j++) {
                dp[i][j][1] = MAXCOST;
                dp[i][j][0] = -1;
            }
        }

        map.clear();
        // fill(begin(check_subway), end(check_subway), 0);
        // fill(begin(check_node), end(check_node), 0);
        
        int tmp_data;
        for(int subway = 0; subway < n; subway++){
            vector<vector<int> > tmp_arr(n, vector<int>(n));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    //cin >> tmp_data;
                    scanf("%d", &tmp_data);
                    tmp_arr[i][j] = tmp_data;
                }
            }
            map.push_back(tmp_arr);
        }

        //check_node[1] = 1;

        //bfs(1, 0 , 0);

        vector<int>paths;
        vector<int>subwayss;

        dfs2(0, 0, 0);
        min_cost = dp[bitmasking][bitmasking][1];
        max_cost = dp[bitmasking][bitmasking][0];
        if (dp[bitmasking][bitmasking][1] == MAXCOST) min_cost = 0;
        if (dp[bitmasking][bitmasking][0] == -1) max_cost = 0;
        //cout << min_cost << " " << max_cost << endl;
        printf("%d %d\n", min_cost, max_cost);
    }

    return 0;
}
