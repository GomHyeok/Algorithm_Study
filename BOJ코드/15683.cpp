#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m;
int board[9][9];
vector<pair<int, int>> cctv;
int answer = 987654321;

//우상좌하
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void dfs(int indx);
void detect(int x, int y, int direc);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6) {
                cctv.push_back({i,j});
            }
        }
    }

    dfs(0);

    cout<<answer<<endl;
}

void detect(int x, int y, int direct) {
    direct %=4;

    while(1) {
        int nx = x + dx[direct];
        int ny = y + dy[direct];

        x = nx;
        y = ny;

        if(nx < 0 || ny < 0 || nx >=n || ny >= m) return;
        if(board[nx][ny] == 6) return;
        if(board[nx][ny] != 0) continue;

        board[nx][ny] = -1;
    }
} 

void dfs(int indx) {
    if(indx == cctv.size()) {
        int tmp = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!board[i][j]) tmp++;
            }
        }

        if(tmp < answer) answer = tmp;
        return;
    }

    int x = cctv[indx].first;
    int y = cctv[indx].second;



    for(int i = 0; i < 4; i++) {
        int temp_board[9][9];
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) temp_board[j][k] = board[j][k];
        }

        if(board[x][y] == 1)
            detect(x, y, i);
        else if(board[x][y] == 2){
            detect(x, y, i);
            detect(x, y, i+2);
        }
        else if (board[x][y] == 3){
            detect(x, y, i);
            detect(x, y, i + 1);
        }
        else if (board[x][y] == 4){
            detect(x, y, i);
            detect(x, y, i + 1);
            detect(x, y, i + 2); 
        }
        else if (board[x][y] == 5){
            detect(x, y, i);
            detect(x, y, i + 1);
            detect(x, y, i + 2);
            detect(x, y, i + 3);
        }

        dfs(indx+1);

        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) board[j][k] = temp_board[j][k];
        }
    }
}