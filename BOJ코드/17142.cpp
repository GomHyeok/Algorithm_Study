#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n, m;
int board[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int blank;
int answer = 987654321;
vector<pair<int, int>> virus;
vector<bool> np;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    blank = n*n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>board[i][j];
            
            if(board[i][j] == 2) {
                virus.push_back({i, j});
                np.push_back(false);
            } else if(board[i][j] == 1) blank--;
        }
    }

    for(int i=0; i<m; i++) np[i] = true;

    sort(np.begin(), np.end());

    cout<<blank<<endl;

    do{
        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int count = 0;
        int time = 0;

        //cout<<"test_case"<<endl;

        for(int i=0; i<np.size(); i++) {
            if(np[i]) {
                q.push({0,virus[i]});
                visited[virus[i].first][virus[i].second] = true;
                //cout<<virus[i].first<<" "<<virus[i].second<<endl;
            }
        }

        while(!q.empty()) {
            int cnt = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;

            //cout<<cnt<<" "<<x<<" "<<y<<endl;

            q.pop();
            time = cnt;
            count++;

            if(time > answer) break;

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >=n || ny >= n) continue;
                if(board[nx][ny] == 1) continue;
                if(visited[nx][ny]) continue;

                visited[nx][ny] = true;
                q.push({cnt+1, {nx, ny}});
            }
        }
        //cout<<count<<endl;

        if(time < answer) {
            if(count == blank) {
                answer = time;
            }
        }

    }while(next_permutation(np.begin(), np.end()));

    cout<<answer<<endl;
}