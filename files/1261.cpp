#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int board[101][101];
int n, m;
int answer = 100000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<int, int>> q;
    vector<vector<int>> visited(101, vector<int>(101, -1));

    cin>>n>>m;

    for(int i=1; i<=m; i++) {
        string st;
        cin>>st;

        for(int j=1; j<=n; j++) {
            board[i][j] = st[j-1]-'0';
            visited[i][j] = 999999;
        }
    }

    q.push({1,1});
    visited[1][1] = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <=0 || ny<=0 || nx > m || ny > n) continue;


            if(board[nx][ny] == 1) {
                if(visited[nx][ny] > visited[x][y] + 1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
            else {
                if(visited[nx][ny] > visited[x][y] ) {
                    visited[nx][ny] = visited[x][y];
                    q.push({nx, ny});
                }
            }
        }
    }

    answer = visited[m][n];

    cout<<answer<<endl;
}