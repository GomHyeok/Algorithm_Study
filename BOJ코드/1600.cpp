#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int k,w,h;
int board[201][201];
int visited[201][201];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int hx[8] = {-1, -2 ,-1, -2, 1, 2, 1, 2};
int hy[8] = {-2, -1, 2, 1, -2, -1, 2, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<int, pair<int, int>>> q;

    cin>>k;
    cin>>w>>h;

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin>>board[i][j];
        }
    }

    q.push({0, {0, 0}});

    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;

        cout<<x<<" "<<y<<" "<<cnt<<endl;

        q.pop();

        if(cnt > visited[x][y]) continue;
        if(x == h-1 && y == w-1) continue;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <0 || ny <0 || nx >= h || ny >= w) continue;
            if(visited[nx][ny] != 0 && visited[nx][ny] >= cnt + 1) continue;
            if(board[nx][ny] == 1) continue;

            q.push({cnt + 1, {nx, ny}});
            visited[nx][ny] = cnt+1;
        }

        for(int i=0; i<8; i++) {
            int nx = x + hx[i];
            int ny = y + hy[i];

            if(nx <0 || ny <0 || nx >= h || ny >= w) continue;
            if(visited[nx][ny] != 0 && visited[nx][ny] >= cnt + 1) continue;

            q.push({cnt + 1, {nx, ny}});
            visited[nx][ny] = cnt+1;
        }
    }
    

    cout<<visited[h-1][w-1]<<"\n";
}