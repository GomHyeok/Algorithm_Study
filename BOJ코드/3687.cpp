#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int count[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long dp[101];
int number[8] = {-1, -1, 1, 7, 4, 2, 0, 8};
vector<pair<long long, string>> answer;

int n, test;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>test;

    memset(dp, 0x7f, sizeof(dp));

    for(int i=0; i<8; i++) {
        dp[i] = number[i];
    }
    dp[6] = 6;
    dp[1] = 9;

    for(int i=8; i<=100; i++) {
        for(int j=2; j<=7; j++) {
            dp[i] = min(dp[i], dp[i-j]*10 + number[j]);
        }
    }

    while(test > 0) {
        test--;
        long long min_num;
        string max_num;
        int one = 0;
        cin>>n;

        min_num = dp[n];

        one = n/2;
        if(n%2 == 1) {
            max_num = "7";
            for(int i=1; i < one; i++) {
                max_num += "1";
            }
        }
        else {
            max_num = "";
            for(int i=0; i<one; i++) {
                max_num += "1";
            }
        }
        
        answer.push_back({min_num, max_num});
    }

    for(int i=0; i<answer.size(); i++) {
        cout<<answer[i].first<<" "<<answer[i].second<<endl;
    }

}