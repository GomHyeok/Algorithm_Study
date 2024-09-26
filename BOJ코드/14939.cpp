#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

#define MAXINT 987654321

using namespace std;

int board[11][11];
int cBoard[11][11];
int result = MAXINT;
int cnt = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void turnLight(int r, int c) {
    cBoard[r][c] = !cBoard[r][c];
    cnt++;

    for(int i=0; i<4; i++) {
        int nx = r + dx[i];
        int ny = c + dy[i];

        if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
        cBoard[nx][ny] = !cBoard[nx][ny];
    }
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string st;

    for(int i=0; i < 10; i++) {
        cin>>st;
        for(int j=0; j< 10; j++) {
            if(st[j] == 'O') board[i][j] = 1;
        }
    }

    //r == 1 인 경우 1024(2의 10승) 가지 경우의 수
    for(int i=0; i<1024; i++) {
        int p = 1;
        bool flag = true;
        cnt = 0;
        //board 복사
        for(int j = 0; j<10 ; j++) {
            for(int k=0; k<10; k++) {
                cBoard[j][k] = board[j][k];
            }
        }
        //bit연산자 사용해서 해당 위치 스위치 누르는 경우 
        for(int j=0; j<10; j++) {
            if(i&p) {
                turnLight(0, j);
            }

            p *= 2;
        }
        //각 자리의 위의 불이 켜져 있는 경우
        for(int r = 1; r < 10; r++) {
            for(int c = 0; c< 10; c++) {
                if(cBoard[r-1][c]) {
                    turnLight(r, c);
                }
            }
        }

        //가장 아래 row에 켜진 불 없으면 다 끈거임
        for(int c = 0; c < 10; c++) {
            if(cBoard[9][c]) flag = false;
        }

        if(flag) result = min(cnt, result);
    }

    if(result == MAXINT) result = -1;

    cout<<result<<endl;

}