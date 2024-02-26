#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int n, m;
int board[301][301];
int tmp[301][301];
int dx[4] = {1,-1,0,0};
int dy[4] = {0, 0, 1,-1};
int ice;

bool check_piece();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<int, pair<int, int> >> q;
    int now = 0;

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>board[i][j];
            if(board[i][j] > 0){
                ice++;
                q.push({0, {i, j}});
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        if(now != cnt) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    // cout<<board[i][j]<<" ";
                    board[i][j] -= tmp[i][j];
                    tmp[i][j] = 0;
                }
            }
            now = cnt;
            if(check_piece()) {
                cout<<cnt<<endl;
                return 0;
            }
        }

        int water = 0;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == 0) water++;
        }

        if(board[x][y] - water <= 0) {
            tmp[x][y] = board[x][y];
            ice--;
        } else {
            tmp[x][y] = water;
            q.push({cnt +  1, {x, y}});
        }
    }

    cout<<0<<endl;

}

bool check_piece() {
    bool visited[n][m];
    memset(visited, false, sizeof(visited));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] > 0 && !visited[i][j]) {
                queue<pair<int, int>> q;
                int sum = 1;
                q.push({i, j});
                visited[i][j] = true;
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx <0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(visited[nx][ny]) continue;
                        if(board[nx][ny] == 0) continue;

                        q.push({nx, ny});
                        sum++;
                        visited[nx][ny] = true;
                    }
                }
                if(sum != ice) return true;
                else return false;
            }
        }
    }

    return false;
}