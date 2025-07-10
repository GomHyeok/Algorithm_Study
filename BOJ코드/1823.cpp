#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int answer;
int n;
vector<int> rice;
int dp[2001][2001];

int dfs(int left, int right, int cnt);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        int r;
        cin>>r;
        rice.push_back(r);
    }

    cout<<dfs(0, n-1, 1)<<endl;
    
}

int dfs(int left, int right, int cnt) {
    if(left > right) return 0;
    if(dp[left][right] != 0) return dp[left][right];

    dp[left][right] = max(dfs(left+1, right, cnt+1) + rice[left]*cnt, dfs(left, right-1, cnt+1) + rice[right]*cnt);

    return dp[left][right];
}