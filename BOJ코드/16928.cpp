#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int n, m;
int board[101];
bool visited[101];
int answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<pair<int, int> > q;

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        board[x] = y;
    }

    for(int i=0; i<m; i++) {
        int x, y;
        cin>>x>>y;
        board[x] = y;
    }

    q.push({1, 0});

    visited[1] = true;

    while(!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(now == 100) {
            answer = cnt;
            break;
        }

        for(int i=1; i<=6; i++) {
            if(now + i > 100) {
                continue;
            }

            if(board[now + i] > 0) {
                int pos = now + i;
                while(board[pos] > 0) {
                    pos = board[pos];
                }
                if(visited[pos]) continue;
                visited[pos] = true;
                q.push({pos, cnt+1});
            }
            else {
                if(visited[now+i]) continue;
                visited[now + i] = true;
                q.push({now+i, cnt + 1});
            }
        }
    }

    cout<<answer<<endl;
}