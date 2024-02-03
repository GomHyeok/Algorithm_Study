#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#define MAX_VAL 999999

using namespace std;

int n;
vector<int> answer;
int board[126][126];
int dijk[126][126];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<pair<int, int>> q;

    while(1) {
        cin>>n;

        if(n == 0) break;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin>>board[i][j];
                dijk[i][j] = MAX_VAL;
            }
        }

        dijk[0][0] = board[0][0];

        q.push({0, 0});

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(int i=0; i<4; i++) {
                int dx = x + nx[i];
                int dy = y + ny[i];

                if(dx < 0 || dy <0 || dx >= n || dy >= n) continue;

                if(dijk[dx][dy] == MAX_VAL || dijk[x][y] + board[dx][dy] < dijk[dx][dy]) {
                    q.push({dx, dy});
                    dijk[dx][dy] = dijk[x][y] + board[dx][dy];
                }
            }
        }

        answer.push_back(dijk[n-1][n-1]);
    }

    for(int i=0; i<answer.size(); i++) {
        printf("Problem %d: %d\n", i+1, answer[i]);
    }

}