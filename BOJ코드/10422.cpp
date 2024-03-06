#include <iostream>
#include <algorithm>
#include <vector>
#define DIV 1000000007


using namespace std;

int test;
vector<long long> answers;
long long dp[5001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>test;

    dp[0]=1;

    for(int i = 2; i<=5000; i+=2) {
        for(int j=2; j<=i; j+=2) {
            dp[i] += dp[j-2] * dp[i-j];
            dp[i] %= DIV;
        }
    }

    while(test > 0) {
        test--;
        int l;

        cin>>l;

        answers.push_back(dp[l]);
    }

    for(int i=0; i<answers.size(); i++) {
        cout<<answers[i]<<endl;
    }

}