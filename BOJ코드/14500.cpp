#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

int n, m, answer;
int board[500][500];
bool visited[500][500];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int compare(int a, int b) {
    if(a > b) {
        return a;
    }
    return b;
}

void dfs(int x, int y, int sum, int cnt);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    
    for(int i = 0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>board[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            dfs(i, j, board[i][j], 0);
            //ㅗ모양이 변수임 왜냐? 연속된 4개에서 한칸 삐쭉 빠져나갈 수 있기 때문에, 다른 건 그냥 4*4모양 안에서 전부 완성 가능함
            if (i - 1 >= 0 && j + 2 < m) {
                int tmp = 0;
                tmp = board[i][j] + board[i][j+1] + board[i][j+2] + board[i-1][j+1];
                answer = compare(answer, tmp);
            }
            if (j + 2 < m && i + 1 < n) {
                int tmp = 0;
                tmp = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+1];
                answer = compare(answer, tmp);
            }
            if (i + 2 < n && j + 1 < m) {
                int tmp = 0;
                tmp = board[i][j] + board[i+1][j] + board[i + 2][j] + board[i+1][j+1];
                answer = compare(answer, tmp);
            }
            if (i + 1 < n && i - 1 >= 0 && j + 1 < m) {
                int tmp = 0;
                tmp = board[i][j] + board[i-1][j+1] + board[i][j + 1] + board[i+1][j+1];
                answer = compare(answer, tmp);
            }
        }
    }
    
    cout<<answer<<endl;
}

void dfs(int x, int y, int sum, int cnt) {
    visited[x][y] = true;
    
    if(cnt == 3) {
        answer = compare(answer, sum);
        return;
    }
    
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visited[nx][ny] == true) continue;
 
        dfs(nx, ny, sum + board[nx][ny], cnt + 1);
        visited[nx][ny] = false;
    }
    
    visited[x][y] = false;
}
