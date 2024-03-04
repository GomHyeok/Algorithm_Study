#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define MAX_VAL 9999999

using namespace std;

int n;
int board[100000][3];
int dp[100000][3][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>board[i][0]>>board[i][1]>>board[i][2];
        dp[i][0][0] = MAX_VAL;
        dp[i][1][0] = MAX_VAL;
        dp[i][2][0] = MAX_VAL;
    }

    dp[n-1][0][0] = board[n-1][0];
    dp[n-1][0][1] = board[n-1][0];
    dp[n-1][1][0] = board[n-1][1];
    dp[n-1][1][1] = board[n-1][1];
    dp[n-1][2][0] = board[n-1][2];
    dp[n-1][2][1] = board[n-1][2];

    for(int i=n-2; i>=0; i++) {
        if(dp[i][0][0] > dp[i-1][0][0] + board[i][0]) dp[i][0][0] = dp[i-1][0][0] + board[i][0];
        if(dp[i][0][0] > dp[i-1][1][0] + board[i][1]) dp[i][0][0] = dp[i-1][1][0] + board[i][1];
        if(dp[i][1][0] > dp[i-1][0][0] + board[i][0]) dp[i][0][0] = dp[i-1][0][0] + board[i][0];
        if(dp[i][1][0] > dp[i-1][1][0] + board[i][1]) dp[i][1][0] = dp[i-1][1][0] + board[i][1];
        if(dp[i][1][0] > dp[i-1][2][0] + board[i][2]) dp[i][2][0] = dp[i-1][2][0] + board[i][2];
        if(dp[i][2][0] > dp[i-1][1][0] + board[i][1]) dp[i][1][0] = dp[i-1][1][0] + board[i][1];
        if(dp[i][2][0] > dp[i-1][2][0] + board[i][2]) dp[i][2][0] = dp[i-1][1][0] + board[i][1];
    }
    

    
}