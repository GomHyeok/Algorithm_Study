#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int k;
vector<pair<int, int>> things;
int dp[101][100001];
int w[101];
int v[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>k;

    for(int i=1; i<=n; i++) {
        cin>>w[i]>>v[i];
    }

    for(int i=0; i<=k ;i++) {
        for(int j=1; j<=n; j++) {
            if(w[j] > i) {
                dp[j][i] = dp[j-1][i];
            }
            else {
                dp[j][i] = max(dp[j-1][i-w[j]] + v[j], dp[j-1][i]);
            }
        }
    }

    // for(int i=1; i<=n; i++) {
    //     for(int j=0; j<=k; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    cout<<dp[n][k]<<endl;

}