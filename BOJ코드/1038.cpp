#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
long long dp[10000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int index = 10;
    queue<long long> q;

    cin>>n;

    for(int i=1; i<10; i++) {
        q.push(i);
        dp[i] = i;
    }

    if(n<=10) {
        cout<<n<<endl;
        return 0;
    }

    while(index <= n && !q.empty()) {
        long long num = q.front();
        q.pop();

        long long last = num%10;
        for(long long i=0; i<last; i++) {
            q.push(num*10 + i);
            dp[index++] = num*10 + i;
        }
    }    

    if(dp[n] != 0) cout<<dp[n]<<endl;
    else cout<<-1<<endl;
}