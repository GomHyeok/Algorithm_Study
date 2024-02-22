#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#define MIN_VAL -99999999;

using namespace std;

int n, m;
int board[1001][1001];
long long visited[1001][1001][3];
bool check[1001][1001];

int dx[3] = {0, 0, 1};
int dy[3] = {-1, 1, 0};

long long dfs(int x, int y, int dir);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    memset(visited, -1, sizeof(visited));

    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>board[i][j];
        }
    }

    long long result = dfs(1, 1, 0);

    cout<<result<<endl;

}

long long dfs(int x, int y, int dir) {
    if(x == n && y == m) {
        return board[x][y];
    }

    long long &ret = visited[x][y][dir];
    if(ret != -1) return ret;
    ret = MIN_VAL;
    check[x][y] = true;

    for(int i=0; i<3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <1 || ny <1 || nx > n || ny > m || check[nx][ny]) continue;

        ret = max(ret, dfs(nx, ny, i) + board[x][y]);
    }

    check[x][y] = false;

    return ret;
}