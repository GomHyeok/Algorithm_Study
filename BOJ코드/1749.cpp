#include<iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n, m;
int board[201][201];
int answer = -987654321;

int find(int a, int b) {
    int num = -987654321;
    for(int i=1; i<=n-i+1; i++) {
        for(int j=1; j<=m; j++) {
            num = max(num, board[i+a-1][j+b-1] - board[i-1][j+b-1] - board[i+a-1][j-1] + board[i-1][j-1]);
        }
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
            board[i][j]+=board[i][j-1]+board[i-1][j]-board[i-1][j-1];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            answer = max(answer, find(i, j));
        }
    }
}