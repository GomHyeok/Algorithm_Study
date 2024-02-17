#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};
int r, c;

queue<pair<int, int>> fire;
queue<pair<pair<int, int>, int>> pos;
string board[1000];
int dist[1000][1000];
int visited[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>r>>c;

    for(int i=0; i<r; i++) {
        string st;
        cin>>st;
        board[i] = st;
        for(int j=0; j<c; j++) {
            dist[i][j] = -1;
            if(st[j] == 'J') {
                pos.push({{i, j}, 0});
            }
            if(st[j] == 'F') {
                fire.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while(!fire.empty()) {
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();

        for(int i=0; i<4; i++) {
            int dx = x + nx[i];
            int dy = y + ny[i];

            if(dx < 0 || dy < 0 || dx >= r || dy >= c) continue;
            if(dist[dx][dy] >= 0 || board[dx][dy] == '#') continue;

            dist[dx][dy] = dist[x][y] + 1;
            fire.push({dx, dy});
        }
    }

    // for(int i=0; i<r; i++) {
    //     for(int j=0; j<c; j++) {
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    while(!pos.empty()) {
        int x  = pos.front().first.first;
        int y  = pos.front().first.second;
        int cnt = pos.front().second;

        // cout<<x<<" "<<y<<" "<<cnt<<endl;

        pos.pop();

        for(int i=0; i<4; i++) {
            int dx = x + nx[i];
            int dy = y + ny[i];
            if(dx < 0 || dy < 0 || dx >= r || dy >= c) {
                cout<<cnt+1<<endl;
                return 0;
            }
            if(visited[dx][dy]) continue;
            if(board[dx][dy] == '#') continue;
            if(cnt+1 >= dist[dx][dy] && dist[dx][dy] != -1) continue;
            visited[dx][dy] = true;

            pos.push({{dx, dy}, cnt + 1});
        }
    }

    cout<<"IMPOSSIBLE"<<endl;

}