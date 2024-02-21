#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int n;
int dp[50001];
vector<int> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, int>> money;

    for(int tc=0; tc<3; tc++) {
        cin>>n;
        money.clear();
        memset(dp, 0, sizeof(dp));
        int a, b;
        int total = 0;

        dp[0] = 1;

        for(int j=0; j<n; j++) {
            cin>>a>>b;
            money.push_back({a,b});
            total += (a*b);
        }

        if(total % 2 != 0) {
            answer.push_back(0);
            continue;
        }

        sort(money.begin(), money.end());

        for(int i=0; i<n; i++) {
            for(int j = total/2; j>=money[i].first; j--) {
                if(dp[j - money[i].first]) {
                    for(int k=0; k<money[i].second; k++) {
                        if(j + k * money[i].first > total/2) break;
                        dp[j + k*money[i].first] = 1;
                    }
                }
            }
        }

        answer.push_back(dp[total/2]);
    }

    for(int i=0; i<3; i++) {
        cout<<answer[i]<<endl;
    }


}