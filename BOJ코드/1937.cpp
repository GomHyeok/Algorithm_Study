#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int arr[501][501];
int N;
int dp[501][501];

int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };

int find_max_life(int i, int j){
    if(dp[i][j] > 0){
        return dp[i][j];
    }
    
    dp[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int nextX = i + dx[k];
        int nextY = j + dy[k];

        if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;
        if(arr[i][j] >= arr[nextX][nextY]) continue;

        dp[i][j] = max(dp[i][j], find_max_life(nextX, nextY) + 1);
    }
    
    return dp[i][j];
}

int main(){
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            dp[i][j] = 0;
        }
    }
    
    int maxRice = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
           maxRice = max(maxRice, find_max_life(i, j));
        }
        cout << '\n';
    }
    
    cout << maxRice <<'\n';
    
  
    return 0;
}