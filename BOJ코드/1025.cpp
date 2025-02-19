#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

bool checkSquare(long long num);
void makeNum(int x, int y, int dx, int dy);
int reverseNum(int num);

long long answer = -1;
int board[10][10];
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        string st;
        cin>>st;
        for(int j=0; j<m; j++) {
            board[i][j] = st[j] - '0';
            if(checkSquare(board[i][j]) && board[i][j] > answer) answer = board[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<n; k++) {
                for(int l=0; l<m; l++) {
                    makeNum(i, j, k, l);
                }
            }
        }
    }

    //makeNum(4, 0, 1, 2);

    cout<<answer<<endl;
}

bool checkSquare(long long num) {
    int check = int(sqrt(num));
    //cout<<num<<" "<<check<<endl;
    if((check*check) == num) return true;
    return false;
}

void makeNum(int x, int y, int dx, int dy) {
    int num = 0;
    int nx = x;
    int ny = y;
    if(dx ==0 && dy == 0) return;

    while(nx < n && ny < m) {
        num = (num * 10) + board[nx][ny];
        //cout<<num<<" "<<reverseNum(num)<<endl;
        if(checkSquare(reverseNum(num)) && answer < reverseNum(num)) answer = reverseNum(num);
        if(checkSquare(num) && answer < num) answer = num;
        nx += dx;
        ny += dy;
    }

    num = 0;
    nx = x;
    ny = y;

    while(nx >= 0 && ny >= 0) {
        num = (num * 10) + board[nx][ny];
        //cout<<num<<" "<<reverseNum(num)<<endl;
        if(checkSquare(reverseNum(num)) && answer < reverseNum(num)) answer = reverseNum(num);
        if(checkSquare(num) && answer < num) answer = num;
        nx -= dx;
        ny -= dy;
    }

    num = 0;
    nx = x;
    ny = y;

    while(nx >= 0 && ny < m) {
        num = (num * 10) + board[nx][ny];
        //cout<<num<<endl;
        if(checkSquare(reverseNum(num)) && answer < reverseNum(num)) answer = reverseNum(num);
        if(checkSquare(num) && answer < num) answer = num;
        nx -= dx;
        ny += dy;
    }

    num = 0;
    nx = x;
    ny = y;

    while(nx < n && ny >= 0) {
        num = (num * 10) + board[nx][ny];
        //cout<<num<<endl;
        if(checkSquare(reverseNum(num)) && answer < reverseNum(num)) answer = reverseNum(num);
        if(checkSquare(num) && answer < num) answer = num;
        nx += dx;
        ny -= dy;
    }
}

int reverseNum(int num) {
    int result = 0;
    while(num > 0) {
        result = (result * 10) + num%10;
        num /= 10;
    }

    return result;
}