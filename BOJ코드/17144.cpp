#include <iostream>
#include <vector>

using namespace std;

int R,C,T;
vector<int> air;
int board[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
long long answer = 0;

void makeDust();
void clearDustUP();
void clearDustDOWN();
void printBoard();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C>>T;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin>>board[i][j];
            if(board[i][j] == -1) air.push_back(i);
        }
    }

    for(int i=0; i<T; i++) {
        makeDust();
        clearDustUP();
        clearDustDOWN();
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(board[i][j] > 0) answer+=board[i][j];
        }
    }

    cout<<answer<<endl;

}

void makeDust() {
    vector<vector<int>> tmp(50, vector<int>(50, 0));

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(board[i][j] >= 5) {
                int cnt = board[i][j] / 5;
                for(int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                    if(nx==air[0] && ny == 0) continue;
                    if(nx == air[1] && ny == 0) continue;
                    tmp[nx][ny] += cnt;
                    board[i][j] -= cnt;
                }
            }
        }
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            board[i][j] += tmp[i][j];
        }
    }
}

void clearDustUP() {
    int up = air[0];
    int past = 0;

    //past = 0
    for(int i=1; i<C-1; i++) {
        int tmp = board[up][i];
        board[up][i] = past;
        past = tmp;
    }

    //past = board[up][c-2]
    for(int i=up; i>0; i--) {
        int tmp = board[i][C-1];
        board[i][C-1] = past;
        past = tmp;
    }

    //past = board[1][c-1]
    for(int i = C-1; i>0; i--) {
        int tmp = board[0][i];
        board[0][i] = past;
        past = tmp;
    }

    //past = board[0][1]
    for(int i=0; i<up; i++) {
        int tmp = board[i][0];
        board[i][0] = past;
        past = tmp;
    }
}

void clearDustDOWN() {
    int down = air[1];
    int past = 0;

    //past = 0
    for(int i=1; i<C-1; i++) {
        int tmp = board[down][i];
        board[down][i] = past;
        past = tmp;
    }

    //past = board[down][c-2]
    for(int i=down; i<R-1; i++) {
        int tmp = board[i][C-1];
        board[i][C-1] = past;
        past = tmp;
    }

    //past = board[R-2][C-1]
    for(int i = C-1; i>0; i--) {
        int tmp = board[R-1][i];
        board[R-1][i] = past;
        past = tmp;
    }

    //past = board[R-1][1]
    for(int i=R-1; i>down; i--) {
        int tmp = board[i][0];
        board[i][0] = past;
        past = tmp;
    }
}

void printBoard() {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}