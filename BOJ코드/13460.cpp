#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int board[10][10];
bool visited[10][10][10][10];
int n,m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
pair<int, int> finish;
pair<int, int> red;
pair<int, int> blue;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<pair<pair<int, int>, int>, pair<int, int>>> q;

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        string st;
        cin>>st;
        for(int j=0; j<m; j++) {
            if(st[j] == '.') board[i][j] = 1;
            else if(st[j] == 'O') {
                board[i][j] = 1;
                finish = {i,j};
            } else if(st[j] == 'R') {
                board[i][j] = 1;
                red = {i,j};
            } else if(st[j] == 'B') {
                board[i][j] = 1;
                blue = {i,j};
            }
        }
    }

    q.push({{red, 0}, blue});
    visited[red.first][red.second][blue.first][blue.second] = true;
    while(!q.empty()){
        pair<int, int> rpos = q.front().first.first;
        pair<int, int> bpos = q.front().second;
        int cnt = q.front().first.second;
        q.pop();

        if(cnt >= 10) continue;

        if(rpos.first == finish.first && rpos.second == finish.second) {
            if(bpos.first != finish.first || bpos.second != finish.second) {
                cout<<cnt<<"\n";
                return 0;
            }
        }

        for(int i=0; i<4; i++) {
            int rx = rpos.first;
            int ry = rpos.second;
            int rdist = 0;
            int bx = bpos.first;
            int by = bpos.second;
            int bdist = 0;

            while(board[rx+dx[i]][ry+dy[i]] && !(rx == finish.first && ry == finish.second)) {
                rx += dx[i];
                ry += dy[i];
                rdist++;
            }
            while(board[bx+dx[i]][by+dy[i]] && !(bx == finish.first && by == finish.second)) {
                bx += dx[i];
                by += dy[i];
                bdist++;
            }

            if(bx == finish.first && by == finish.second) continue;
            if(rx == finish.first && ry == finish.second) {
                cout<<cnt + 1<<"\n";
                return 0;
            }

            if(rx == bx && ry == by) {
                if(rdist > bdist) {
                    rx -= dx[i];
                    ry -= dy[i];
                } else {
                    bx -= dx[i];
                    by -= dy[i];
                }
            }

            if(visited[rx][ry][bx][by]) continue;
            visited[rx][ry][bx][by] = true;
            q.push({{{rx, ry}, cnt+1}, {bx, by}});
        }
    }

    cout<<-1<<'\n';

}