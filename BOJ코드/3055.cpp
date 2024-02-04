#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<int, int> s;
int r,c;
int answer = -1;
int board[51][51];
bool visited[51][51];
vector<pair<int, int>> waters;

void changeBoard();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int wTime = 0;
    queue<pair<pair<int, int>, int>> q;

    cin>>r>>c;

    for(int i=0; i<r; i++) {
        string st;
        cin>>st;
        for(int j=0; j<c; j++) {
            if(st[j] == 'D') {
                board[i][j] = 10;
            }
            else if(st[j] == '.') {
                board[i][j] = 0;
            }
            else if(st[j] == 'S') {
                s.first = i;
                s.second = j;
                board[i][j] = 5;
            }
            else if(st[j] == 'X') {
                board[i][j] = 1;
            }
            else if(st[j] == '*') {
                board[i][j] = 1;
                waters.push_back({i, j});
            }
        }
    }

    visited[s.first][s.second] = true;

    q.push({{s.first, s.second}, 0});

    changeBoard();

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second;

        q.pop();

        if(board[x][y] == 10) {
            answer = time;
            break;
        }

        if(time != wTime) {
            wTime++;
            changeBoard();
        }

        for(int j=0; j<4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(nx <0 || ny <0 || nx >=r || ny >= c) continue;

            if(board[nx][ny] == 1 || visited[nx][ny]) continue;

            q.push({{nx, ny}, time+1});
            visited[nx][ny] = true; 
        }
    }

    if(answer != -1) {
        cout<<answer<<endl;
    }
    else {
        cout<<"KAKTUS"<<endl;
    }
}

void changeBoard() {
    vector<pair<int, int>> tmp;

    for(int i=0; i<waters.size(); i++) {
        int x = waters[i].first;
        int y = waters[i].second;
        for(int j=0; j<4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(nx <0 || ny <0 || nx >=r || ny >= c) continue;

            if(board[nx][ny] == 0) {
                board[nx][ny] = 1;
                tmp.push_back({nx, ny});
            }
        }
    }

    for(int i=0; i<tmp.size(); i++) {
        waters.push_back(tmp[i]);
    }
}