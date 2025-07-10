#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int answer = -1;
int r, c;
int board[1501][1501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> birds;

bool check(int day);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int left = 0;
    int right = 0;

    queue<pair<int, int>> q;

    cin>>r>>c;

    for(int i=0; i<r; i++) {
        string st;
        cin>>st;
        for(int j=0; j<c; j++) {
            if(st[j] == 'X') board[i][j] = -1;
            else {
                q.push({i, j});
                board[i][j] = 0;
                if(st[j] == 'L') birds.push_back({i, j});
            } 
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int day = board[x][y];
        right = max(right, day);
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(board[nx][ny] != -1) continue;

            board[nx][ny] = day + 1;
            q.push({nx, ny});
        }
    }

    while(left <= right) {
        int mid = (left + right)/2;
        if(check(mid)) {
            right = mid - 1;
            answer = mid;
        } else left = mid + 1;
    }

    cout<<answer<<endl;
}

bool check(int day) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(r+1, vector<bool>(c+1, false));
    q.push(birds[0]);

    visited[birds[0].first][birds[0].second] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == birds[1].first && y == birds[1].second) return true;
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(board[nx][ny] > day) continue;
            if(board[nx][ny] < 0) continue;
            if(visited[nx][ny]) continue;;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return false;
}