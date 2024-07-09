#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int test_case;
int board [100][2];
bool visited[100];

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int t=0; t<10; t++) {
        bool flag = false;
        int n;
        queue<int> q;
        cin>>test_case;
        cin>>n;

        for(int i=0; i<100; i++) {
            board[i][0] = -1;
            board[i][1] = -1;
            visited[i] = false;
        }

        for(int i=0; i<n; i++) {
            int a, b;
            cin>>a>>b;
            if(board[a][0] == -1) board[a][0] = b;
            else board[a][1] = b;
        }

        visited[0] = true;
        q.push(0);

        while(!q.empty()) {
            int now = q.front();
            q.pop();

            if(board[now][0] != -1 && !visited[board[now][0]]) {
                if(board[now][0] == 99) {
                    flag = true;
                    break;
                }
                visited[board[now][0]] = true;
                q.push(board[now][0]);
            }

            if(board[now][1] != -1 && !visited[board[now][1]]) {
                if(board[now][1] == 99) {
                    flag = true;
                    break;
                }
                visited[board[now][1]] = true;
                q.push(board[now][1]);
            }
        }

        cout<<"#"<<test_case<<" ";

        if(flag) cout<<1<<endl;
        else cout<<0<<endl;
    } 
}