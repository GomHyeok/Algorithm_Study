#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int answer;
int board[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int r, int c);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        string st;
        cin>>st;
        for(int j=0; j<m; j++) {
            if(st[i] == 'w') board[i][j] = 1;
            else board[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int value;
            if(board[i][j] == 0) {
                value = dfs(i, j);
                cout<<value<<endl;
                answer = max(answer, value);
            }
        }
    }

    cout<<answer<<"\n";
}

int dfs(int r, int c) {
    int value = 0;
    queue<pair<int, pair<int, int>>> q;
    bool visited[51][51];

    for(int i=0; i<51; i++) {
        for(int j=0; j<51; j++) {
            visited[i][j] = false;
        }
    }

    q.push({1, {r, c}});
    visited[r][c] = true;

    while (!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;

        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <0 || ny <0 || nx>=n || ny >=m) continue;
            if(board[nx][ny]) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            if(cnt + 1 > value) value = cnt + 1;
            q.push({cnt+1, {nx, ny}});
        }
    }

    return value;
}