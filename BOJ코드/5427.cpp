#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0, 0, 1, -1};
int test_case;
int w, h;
int board[1002][1002];
vector<pair<int, int>> fires;

void make_fire();
void print_board();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>test_case;

    while(test_case) {
        pair<int, int> pos;
        queue<pair<int , pair<int, int>>>q;
        
        int fire = -1;
        int answer = -1;

        cin>>w>>h;

        vector<vector<bool>> visited(h + 1, vector<bool>(w + 1, false));

        fires.clear();

        for(int i=0; i<h; i++) {
            string st;
            cin>>st;
            for(int j=0; j<w; j++) {
                if(st[j] =='*') {
                    board[i][j] = 1;
                    fires.push_back({i, j});
                } else if(st[j] == '@') {
                    pos.first = i;
                    pos.second = j;
                } else if(st[j] == '#'){
                    board[i][j] = 1;
                }
            }
        }

        q.push({0, pos});

        while(!q.empty()) {
            int cnt = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;

            // cout<<cnt<<" "<<x<<" "<<y<<endl;

            // print_board();

            q.pop();

            if(x >= h-1 || x <=0 || y >= w-1 || y <= 0) {
                answer = cnt + 1;
                break;
            }

            if(cnt != fire) {
                make_fire();
                fire = cnt;
            }

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx <0 || ny <0 || nx > h || ny > w) continue;
                if(board[nx][ny]) continue;
                if(visited[nx][ny]) continue;

                visited[nx][ny] = true;

                q.push({cnt + 1, {nx, ny}});
            }
        }
        if(answer == -1) cout<<"IMPOSSIBLE"<<endl;
        else cout<<answer<<endl;
        test_case--;
    }
}

void make_fire() {
    vector<pair<int, int>> tmp;
    for(int i=0; i<fires.size(); i++) {
        int x = fires[i].first;
        int y = fires[i].second;

        for(int j=0; j<4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(nx <0 || ny <0 || nx >=h || ny >= w) continue;
            if(board[nx][ny]) continue;

            board[nx][ny] = 1;
            tmp.push_back({nx, ny});  
        } 
    }
    for(int i=0; i<tmp.size(); i++) {
        fires.push_back(tmp[i]);
    }
}

void print_board() {
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}