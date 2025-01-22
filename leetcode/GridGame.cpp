#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int n;
long long answer = 6000000000;
long long maxScore;

long long gridGame(vector<vector<int>>& grid);
void secondGame(vector<vector<int>>& grid, bool check, int x, int y, long long score);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid = {{2, 5, 4}, {1, 5, 1}};
    grid[0][0] = 0;
    gridGame(grid);

    cout<<answer<<endl;
}

void firstGame(vector<vector<int>>& grid, bool check, int x, int y) {
    if(x == 1 && y == n-1) {
        // for(int i=0; i<2; i++) {
        //     for(int j = 0; j<n; j++) {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        maxScore = 0;
        secondGame(grid, true, 0, 0, grid[0][0]);
        answer = min(answer, maxScore);
        return;
    }

    if(check) {
        int tmp = grid[x+1][y];
        grid[x + 1][y] = 0;
        firstGame(grid, false, x+1, y);
        grid[x + 1][y] = tmp;
    }

    if(y < n-1) {
        int tmp = grid[x][y + 1];
        grid[x][y+1] = 0;
        firstGame(grid, check, x, y+1);
        grid[x][y+1] = tmp;
    }
}

void secondGame(vector<vector<int>>& grid, bool check, int x, int y, long long score) {
    if(x == 1 && y == n-1) {
        // cout<<score<<maxScore<<endl;
        maxScore = max(maxScore, score);
        return;
    }

    if(check) {
        secondGame(grid, false, x+1, y, score+grid[x+1][y]);
    }

    if(y < n-1) {
        secondGame(grid, check, x, y+1, score+grid[x][y+1]);
    }
}

//이동은 우, 하 두개만 가능
long long gridGame(vector<vector<int>>& grid) {
    n = grid[0].size();

    // cout<<n<<endl;

    firstGame(grid, true, 0, 0);

    return answer;
}