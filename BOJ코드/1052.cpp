#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

long long n, k;

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
        int temp = n;
        while(temp > 0) {
            if(temp % 2 == 0) {
                temp /= 2;
            } else {
                temp/=2;
                cnt++;
            }
        }
    }
}