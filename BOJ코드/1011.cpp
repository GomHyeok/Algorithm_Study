#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int t;
long long x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t > 0) {
        t--;
        cin>>x>>y;
        double distance = y-x;
        double dpow = sqrt(distance);
        long long pow_val = round(dpow);

        if(dpow <= pow_val) cout<<pow_val * 2 -1 <<'\n';
        else cout<<pow_val * 2 <<'\n';
    }
}