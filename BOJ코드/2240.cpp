#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int t, w;
int dp[2][31][1001];
vector<int> location;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t>>w;

    for(int i=0; i<t; i++) {
        int a;
        cin>>a;
        location.push_back(a-1);
    }

    

}
