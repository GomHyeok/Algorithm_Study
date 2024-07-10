#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int testCase;
char board[4][4];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
map<string, int> check;

void dfs(string st, int x, int y);

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>testCase;

    for(int t=1; t<=testCase; t++) {
        check.clear();
        int answer = 0;
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                int c;
                cin>>c;
                board[i][j] = c + '0';
            }
        }

        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                string st;
                st.push_back(board[i][j]);
                dfs(st, i, j);
            }
        }

        for(auto iter : check) { 
            answer++;
        }

        cout<<"#"<<t<<" "<<answer<<endl;
    }
}

void dfs(string st, int x, int y) {
    if(st.size() == 7) {
        check[st]++;
        return;
    }

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= 4 || ny >=  4) continue;
        
        dfs(st + board[nx][ny], nx, ny);
    }
}