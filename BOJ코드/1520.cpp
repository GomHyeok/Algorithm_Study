#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int n,m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
long long dp[500][500];
int board[500][500];

int dfs(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long answer;

    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>board[i][j];
            dp[i][j] = -1;
        }
    }

    answer = dfs(0, 0);

    cout<<answer<<endl;
}

int dfs(int x, int y) {
    if(x == n-1 && y == m-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(board[x][y] > board[nx][ny]) dp[x][y] += dfs(nx, ny);
    }

    return dp[x][y];
}