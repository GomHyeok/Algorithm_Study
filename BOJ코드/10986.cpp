#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <vector>

using namespace std;

long long n, m;
long long sum;
long long answer;
long long mods[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        long long num;
        cin>>num;
        sum += num;
        mods[sum%m]++;
    }

    for(int i=0; i<=m; i++) {
        answer += ((mods[i] * (mods[i]-1)) / 2);
    }

    cout<<mods[0] + answer<<endl;

}