#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int h, w;
int sr, sc;
int fr, fc;
int answer = 1000000;
int board[1001][1001];
int visited[1001][1001];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs();
bool check(int x, int y, int i);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>board[i][j];
        }
    }

    cin>>h>>w>>sr>>sc>>fr>>fc;
    h--;
    w--;

    bfs();

    if(answer == 1000000) {
        cout<<-1<<endl;
    }
    else {
        cout<<answer<<endl;
    }
}

void bfs() {
    queue<pair<int, pair<int, int>>> q;

    q.push({0, {sr, sc}});
    visited[1][1] = true;

    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;

        int cnt = q.front().first;

        //cout<<x<<" "<<y<<" "<<cnt<<endl;

        if(x ==fr && y == fc) {
            if(cnt < answer) {
                answer = cnt;
                break;
            }
        }

        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <=0 || ny <=0 || nx > n || ny > m) continue;
            if(nx + h > n || ny + w > m) continue;
            if(visited[nx][ny]) continue;
            if(!check(nx, ny, i)) continue;

            q.push({cnt+1, {nx, ny}});
            visited[nx][ny] = true;
        }
    }
}

bool check(int x, int y, int i) {
    switch(i) {
        case(0) :
            x += h;
            for(int j=0; j<w+1; j++) {
                if(board[x][y + j] == 1) return false;
            }
            break;
        case(1) :
            for(int j=0; j<w+1; j++) {
                if(board[x][y + j] == 1) return false;
            }
            break;
        case(2) :
            y += w;
            for(int j=0; j<h+1; j++) {
                if(board[x + j][y] == 1) return false;
            }
            break;
        case(3) : 
            for(int j=0; j<h+1; j++) {
                if(board[x + j][y] == 1) return false;
            }
            break;
    }

    return true;
}