#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool board[101][101];

//이동은 무조건 Index + 1
//시작 x, y 위치 주의
//방문 점 체크, 그러고 정사각형 가능한지 dfs로 판단(0~99, 0~99)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        int x, y, d, g;
        int line;
        vector<int> dir;
        cin>>x>>y>>d>>g;

        line = pow(2, g);
        dir.push_back(d);

        board[y][x] = true;

        for(int j = 1; j<line; j++) {
            
        }
    }
}

/*
0
1 -> 0, 1
21 -> 0, 1, 2, 1
2321 -> 0, 1, 2, 1, 2, 3, 2, 1
*/

