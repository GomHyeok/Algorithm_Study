#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define MAX_VAL 9999999

using namespace std;

int board[100][100];
bool visited_lever[100][100];
bool visited_exit[100][100];
int dx[4] = {1, -1 ,0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<string> maps) {
    int answer = 0;
    bool flag = true;
    pair<int, int> start;
    pair<int, int> end;
    pair<int, int> lever;
    queue<pair<int, pair<int, int>>> q;
    queue<pair<int, pair<int, int>>> q2;
    
    for(int i=0; i<maps.size(); i++) {
        for(int j=0; j<maps[i].size(); j++) {
            if(maps[i][j] == 'S') {
                start.first = i;
                start.second = j;
                board[i][j] = 1;
            } else if (maps[i][j] == 'E') {
                end.first = i;
                end.second = j;
                board[i][j] = 1;
            } else if (maps[i][j] == 'L') {
                lever.first = i;
                lever.second = j;
                board[i][j] = 1;
            } else if (maps[i][j] == 'O') {
                board[i][j] = 1;
            } 
        }
    }
    
    q.push({0, start});
    
    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();
        
        if(x == lever.first && y == lever.second) {
            answer += cnt;
            flag = false;
            break;
        }
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size()) continue;
            if(!board[nx][ny]) continue;
            if(visited_lever[nx][ny]) continue;
            
            q.push({cnt + 1, {nx, ny}});
            visited_lever[nx][ny] = true;
        }
    }
    
    if(flag) {
        return -1;
    }
    
    flag = true;
    
    q2.push({0, lever});
    
    while(!q2.empty()) {
        int x = q2.front().second.first;
        int y = q2.front().second.second;
        int cnt = q2.front().first;
        q2.pop();
        
        if(x == end.first && y == end.second) {
            answer += cnt;
            flag = false;
            break;
        }
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size()) continue;
            if(visited_exit[nx][ny]) continue;
            if(!board[nx][ny]) continue;
            
            q2.push({cnt + 1, {nx, ny}});
            visited_exit[nx][ny] = true;
        }
    }
    
    if(flag) {
        return -1;
    }
    
    return answer;
}