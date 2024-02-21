#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

long long a, b;
long long dp[55];

long long count(long long n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long pos = 1;

    cin>>a>>b;

    dp[0] = 1;

    for(int i=1; i<55; i++) {
        dp[i] = dp[i-1] * 2 + 2*pos;
        pos*=2;
    }

    long long front = count(a-1);
    long long back = count(b);

    cout<<back - front<<endl;   
}

long long count(long long n) {
    if(n == 1) {
        return 1;
    }
    vector<int> tmp;
    long long result = 0;
    long long pos = 1;
    long long num = n;
    while(num!=0) {
        tmp.push_back(num % 2);
        num /= 2;
        pos *= 2;
    }

    for(int i=tmp.size()-1; i>=0; i--) {
        pos /= 2;
        if(tmp[i]) {
            if(i == 0) result += 1;
            else {
                result += (dp[i-1] + n - pos + 1);
                n-=pos;
            }
        }
    }

    return result;
}