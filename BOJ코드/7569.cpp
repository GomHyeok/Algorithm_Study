#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n, m, h;
int board[100][100][100];
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};
int sum;
int check;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<pair<int, int>, pair<int, int> > > q;

    cin>>m>>n>>h;

    check = n*m*h;

    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                cin>>board[i][j][k];
                if(board[i][j][k] == 1) {
                    q.push({{j,k}, {i, 0}});
                    sum++;
                }
                if(board[i][j][k] == -1) {
                    check--;
                }
            }
        }
    }

    if(sum == check) {
        cout<<0<<endl;
        return 0;
    }

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second.first;
        int cnt = q.front().second.second;
        answer = cnt;

        q.pop();

        for(int i=0; i<6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nx <0 || ny <0 || nz <0|| nx >= n|| ny >= m|| nz >= h) continue;
            if(board[nz][nx][ny] == 1 || board[nz][nx][ny] == -1) continue;

            board[nz][nx][ny] = 1;
            sum++;

            q.push({{nx, ny}, {nz, cnt + 1}});
        }
    }

    if(sum == check) {
        cout<<answer<<endl;
    }
    else {
        cout<<-1<<endl;
    }

}