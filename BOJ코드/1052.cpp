#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

long long n, k;
long long answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;

    if(k>=n) {
        cout<<0<<endl;
        return 0;
    }

    while(1) {
        int cnt = 0;
        int tmp = n;

        while(tmp > 0) {
            if(tmp%2 != 0) cnt++;
            tmp /= 2;
        }

        if(cnt <= k) break;

        answer++;
        n++;
    }

    cout<<answer<<endl;
}