#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int n, m;
int dp[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i!=j) dp[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++) {
        int f, t, c;
        cin>>f>>t>>c;
        dp[f][t] = min(dp[f][t], c);
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(dp[i][j] == INF) cout<<0<<" ";
            else cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

}