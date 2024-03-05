#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string st1, st2;
    string result;

    cin>>st1>>st2;

    // for(int i=0; i<= st1.size(); i++) {
    //     for(int j=0; j<=st2.size(); j++) {
    //         dp2[i][j] = "";
    //     }
    // }

    for(int i=1; i<=st1.size(); i++) {
        for(int j=1; j<=st2.size(); j++) {
            if(st1[i-1] == st2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i = st1.size();
    int j = st2.size();

    while(i >= 1 && j >= 1) {
        if(dp[i][j] > dp[i-1][j] && dp[i-1][j] == dp[i][j-1] && dp[i][j-1] == dp[i-1][j-1]){
            result = st2[j-1] + result;
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1] && dp[i-1][j] == dp[i][j]) {
            i--;
        } else if(dp[i-1][j] < dp[i][j-1] && dp[i][j-1] == dp[i][j]) {
            j--;
        } else {
            j--;
        }
    }

    if(dp[st1.size()][st2.size()] == 0) {
        cout<<dp[st1.size()][st2.size()]<<endl;
    }
    else {
        cout<<dp[st1.size()][st2.size()]<<endl;
        cout<<result<<endl;
    }

}