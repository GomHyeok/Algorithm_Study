#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int r, c;
int answer;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int board[20][20];
bool check[27];

void dfs(int x, int y, int cnt);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>r>>c;

    for(int i=0; i<r; i++) {
        string st;
        cin>>st;

        for(int j=0; j<c; j++) {
            board[i][j] = st[j] - 'A';
        }
    }

    check[board[0][0]] = true;
    dfs(0, 0, 1);

    cout<<answer<<endl;

}

void dfs(int x, int y, int cnt) {
    bool flag = false;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0  || nx >= r || ny >= c) continue;
        if(check[board[nx][ny]]) continue;

        flag = true;

        check[board[nx][ny]] = true;
        dfs(nx, ny, cnt+1);
        check[board[nx][ny]] = false;
    }

    if(!flag) {
        if(answer < cnt) {
            answer = cnt;
        }
    }
}