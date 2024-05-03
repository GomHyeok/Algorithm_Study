#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
 
using namespace std;
int n;
int map[22][22];
int dx[] = {0, -1, 1, 0}; 
int dy[] = {-1, 0, 0, 1};
int bx, by;
int result = 0; 
int cnt = 0; 
int sz = 2; 
bool eat = false; 
bool visit[21][21];

void bfs(int a, int b, int shSize){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(a, b), 0));
    visit[b][a] = true;
    int temp = 999999999; 
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second; 
        int cnt = q.front().second; 

        q.pop();
        
        //생각을 해보면 상좌하우로 확인하는데 좌->하 이동이 확인이 먼저됨
        //그러면 우->상으로 이동하는 경우가 늦게 확인되서 먹어야 하는 상어 위치달라짐
        if(map[y][x] > 0 && map[y][x] <shSize && temp == cnt){
            if((by > y) || (by == y && bx > x)){
                by = y; 
                bx = x;
                continue;
            }
        }

        if(cnt > temp) continue;
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i]; 
            int ny = y + dy[i];
 
            if(nx>=0 && nx <n && ny>=0 && ny <n && !visit[ny][nx]){
                if(map[ny][nx] <= shSize){
                    //먹을 수 있는 상어가 있고 아직 먹은걸로 판명나지 않은경우
                    if(map[ny][nx] > 0 && map[ny][nx] < shSize && !eat){ 
                        eat = true;
                        bx = nx; 
                        by = ny;
                        temp = cnt + 1;
                        result += temp; 
                    }else{ 
                        q.push(make_pair(make_pair(nx, ny), cnt + 1));
                        visit[ny][nx] = true;  
                    }                      
                }
            }
        }
    }
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                by = i; 
                bx = j;
                map[i][j] = 0;
            }
        }
    }
 
    while(1){
        memset(visit, 0, n*21);
        bfs(bx, by, sz); 
        //상어를 먹을 수 있는 경우
        if(eat){ 
            eat = false; 
            cnt += 1; 
            map[by][bx] = 0; 
            if(cnt == sz){ 
                sz += 1; 
                cnt = 0; 
            }
        }else{ 
            break;
        }
    }
    cout << result << '\n';
    return 0;
}
