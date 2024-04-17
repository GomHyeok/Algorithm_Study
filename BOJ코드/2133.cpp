#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
int dp[31];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    dp[0] = 1;
    dp[2] = 3;

    if(n%2 != 0) {
        cout<<0<<endl;
        return 0;
    }

    for(int i=4; i<=n; i+=2) {
        dp[i]  = dp[i-2] * 3 + 2;
        for(int j=4; j<i; j+=2) {
            dp[i] += dp[i-j]*2;
        }
    }

    cout<<dp[n]<<endl;
}