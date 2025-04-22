#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define MAXVAL 9876543210

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;

int solution(vector<vector<int>> board) {
    int answer = MAXVAL;
    n = board.size();
    vector<vector<int>> visited(n, vector<int>(n, MAXVAL));
    queue<pair<pair<int, int>, pair<int, int>>> q;
    
    visited[0][0] = 0;
    visited[0][1] = 100;
    visited[1][0] = 100;
    
    if(board[1][0] != 1) q.push({{0, 100}, {1, 0}});
    if(board[0][1] != 1) q.push({{2, 100}, {0, 1}});
    
    while(!q.empty()) {
        int dir = q.front().first.first;
        int cost = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        
        q.pop();
        
        if(x == n-1 && y == n-1) {
            answer = min(answer, cost);
            continue;
        }
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny] == 1) continue;
            
            if(dir == i) {
                if(visited[nx][ny] + 500 < cost + 100) continue;
                visited[nx][ny] = min(visited[nx][ny], cost + 100);
                q.push({{i, cost + 100}, {nx, ny}});
            } else {
                if(visited[nx][ny] + 500 < cost + 600) continue;
                visited[nx][ny] = min(visited[nx][ny], cost + 600);
                q.push({{i, cost + 600}, {nx, ny}});
            }
        }
    }
    
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) cout<<visited[i][j]<<" ";
    //     cout<<endl;
    // }
    
    answer = visited[n-1][n-1];
    
    return answer;
}