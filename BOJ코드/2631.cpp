#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int child[201];
int dp[201];
int lis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>child[i];
    }

    for(int i=1; i<=n; i++){
        dp[i] = 1;
        for(int j=1; j<i; j++) {
            if(child[j] < child[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        lis = max(lis, dp[i]);
    }

    cout<<n-lis<<endl;
}