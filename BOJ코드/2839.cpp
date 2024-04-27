#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define INF 987654321

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    vector<int> dp(n+1, INF);

    dp[3] = 1;
    if(n >= 5) dp[5] = 1;

    for(int i=4; i<=n; i++) {
        int three = dp[i-3];

        if(dp[i] > three + 1) dp[i] = three + 1;
        
        if(i>=5) {
            if(dp[i] > dp[i-5] + 1) dp[i] = dp[i-5] + 1;
        }
    }

    if(dp[n] == INF) dp[n] = -1;

    cout<<dp[n]<<endl;

}