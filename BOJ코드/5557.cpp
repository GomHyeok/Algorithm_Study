#include <iostream>
#include <vector>

using namespace std;

int n;
int numbers[101];
long long dp[101][21];
long long answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>numbers[i];
    }

    dp[0][numbers[0]] = 1;

    for(int i=1; i<n-1; i++) {
        for(int j=0; j<21; j++) {
            if(dp[i-1][j]) {
                if(j + numbers[i] <= 20) dp[i][j+numbers[i]] += dp[i-1][j];
                if(j - numbers[i] >= 0 ) dp[i][j-numbers[i]] += dp[i-1][j];
            }
        }
    }

    cout<<dp[n-2][numbers[n-1]];

}