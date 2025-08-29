#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int c, n;

int money[21];
int person[21];

vector<int> dp(1100, 987654321);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int answer = 987654321;

    queue<pair<int, int>> q;

    cin>>c>>n;

    for(int i=0; i<n; i++) {
        cin>>money[i]>>person[i];
    }

    dp[0] = 0;

    for(int i=0; i<n; i++) {
        int m = money[i];
        int p = person[i];

        for(int j = p; j<dp.size(); j++) {
            dp[j] = min(dp[j], dp[j-p] + m);
        }
    }

    for(int i=c; i< dp.size(); i++) {
        answer = min(answer, dp[i]);
    }

    cout<<answer<<endl;
}