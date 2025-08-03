#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

long long n, p, q;
long long answer;
map<long long, long long> dp;

long long makeNum(long long a) {
    if(dp[a]) return dp[a];
    dp[a] = makeNum(a/p) + makeNum(a/q);
    return dp[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>p>>q;

    dp[0] = 1;

    cout<<makeNum(n)<<endl;
}