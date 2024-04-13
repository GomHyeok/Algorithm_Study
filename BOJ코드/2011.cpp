#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define MOD 1000000

using namespace std;

int dp[50001];
string st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>st;

    dp[0] = 1;
    dp[1] = 1;

    if(st[0] == '0') {
        cout<<0<<endl;
        return 0;
    }

    for(int i=2; i<=st.size(); i++) {
        if(st[i-1] != '0') dp[i] = (dp[i] + dp[i-1])%MOD;

        int tmp = (st[i-2] - '0')*10 + (st[i-1] - '0');
        if(tmp >= 10 && tmp <= 26) dp[i] = (dp[i] + dp[i-2])%MOD;

    }

    cout<<dp[st.size()]<<endl;

}