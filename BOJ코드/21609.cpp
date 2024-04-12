#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define BLOCK 10

using namespace std;

int n, m;
int board[21][21];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
long long answer;

bool make_group();
bool compare(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b);
void gravity();
void rotation();
void dfs(int x, int y, int cnt, int value);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0; i<=20; i++) {
        for(int j=0; j<=20; j++) {
            board[i][j] = BLOCK + 1;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>board[i][j];
        }
    }
    while(true) {
        if(!make_group()) break;
        gravity();
    }

}

bool make_group() {
    bool visited[21][21];
    int sx;
    int sy;
    int color;
    queue<pair<int, int>> q;
    vector<pair<pair<int, int>, pair<int, int>>> groups;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = false;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int color;
            int row = i;
            int col = j;
            if(visited[i][j]) continue;
            if(board[i][j] == BLOCK) continue;
            if(board[i][j] == -1) continue;

            queue<pair<int, int>> q;
            vector<pair<int, int>> zeros;
            int cnt = 0;
            int zero = 0;
            color = board[i][j];

            q.push({i, j});
            visited[i][j] = true;
            if(board[i][j] == 0) zeros.push_back({i, j});

            while(!q.empty()) {
                cnt++;
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for(int i=0; i<4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(board[nx][ny] == BLOCK) continue;
                    if(board[nx][ny] == -1) continue;
                    if(visited[nx][ny]) continue;

                    if(color == 0) {
                        if(board[nx][ny]) {
                            color = board[nx][ny];
                            if(nx > x) {
                                row = nx;
                                col = ny;
                            } else if(nx == x && ny > y) {
                                row = nx;
                                col = ny;
                            }
                        }
                        else {
                            zero++;
                            zeros.push_back({nx, ny});
                        }
                        q.push({nx, ny});
                        visited[nx][ny] = true;                     
                    } else if(color == board[nx][ny]) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                        if(nx > x) {
                            row = nx;
                            col = ny;
                        } else if(nx == x && ny > y) {
                            row = nx;
                            col = ny;
                        }
                    } else if(board[nx][ny] == 0) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                        zero++;
                        zeros.push_back({nx, ny});
                    }
                }
            }

            for(int k=0; k<zeros.size(); k++) {
                visited[zeros[k].first][zeros[k].second] = false;
            }

            if(cnt < 2) continue;
            if(zero == cnt) continue;
            groups.push_back({{cnt, zero}, {row, col}});
        }
    }

    if(groups.size() < 1) return false;

    sort(groups.begin(), groups.end());

    answer += groups[groups.size()-1].first.first * groups[groups.size()-1].first.first;

    sx = groups[groups.size()-1].second.first;
    sy = groups[groups.size()-1].second.second;
    color = board[sx][sy];

    q.push({sx, sy});
    board[sx][sy] = BLOCK;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >=n || ny >= n) continue;
            if(board[nx][ny] != color && board[nx][ny] != 0) continue;

            board[nx][ny] = BLOCK;
            q.push({nx, ny});
        }
    }

    return true;
}

void gravity() {
    for(int i = n-2; i>=0; i--) {
        for(int j = 0; j <n; j++) {
            int x = i;
            int y = j;
            if(board[i][j] == -1) continue;
            while(1) {
                if(board[x+1][y] != BLOCK) break;

                board[x+1][y] = board[x][y];
                board[x][y] = BLOCK;
                x++;
            }
        }
    }
}