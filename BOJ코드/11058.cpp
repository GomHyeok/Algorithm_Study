#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

long long buffer;
int n;
long long dp[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;

    for(int i=7; i<=n; i++) {
        for(int j=3; i-j>0; j++) {
            dp[i] = max(dp[i], dp[i-j] * (j-1));
        }

        //cout<<i<<" "<<buffer<<" "<<dp[i]<<endl;
    }

    cout<<dp[n]<<endl;

}