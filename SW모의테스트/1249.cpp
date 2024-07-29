#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_VAL 987654321
 
using namespace std;
 
int test_case;
int board[100][100];
int dp[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
 
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin>>test_case;
 
    for(int t = 1; t <= test_case; t++) {
        int n;
        int sx = 0;
        int sy = 0;
        queue<pair<int, int>> q;
        cin>>n;
 
        q.push({sx, sy});
 
        for(int i=0; i<n; i++) {
            string st;
            cin>>st;
            for(int j=0; j<n; j++) {
                board[i][j] = st[j] - '0';
                dp[i][j] = MAX_VAL;
            }
        }
 
        dp[sx][sy] = board[sx][sy];
 
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
 
            for(int k = 0; k <4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(dp[nx][ny] <= dp[x][y] + board[nx][ny])continue;
 
                dp[nx][ny] = dp[x][y] + board[nx][ny];
                q.push({nx, ny});
            }
        }
 
        cout<<"#"<<t<<" "<<dp[n-1][n-1]<<endl;
    }
}