#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;
int build[100001];
int cnt[100001];
int near[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack<pair<int, int>> st;
    stack<pair<int, int>> left;

    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>build[i];
    }

    for(int i=n; i>0; i--) {
        while(!st.empty() && st.top().first <= build[i]) st.pop();
        cnt[i] += st.size();
        if(!st.empty()) near[i] = st.top().second;
        st.push({build[i], i});
    }

    for(int i=1; i<=n; i++) {
        while(!left.empty() && left.top().first <= build[i]) left.pop();
        cnt[i] += left.size();
        if(!left.empty()){
            if(!near[i] || (near[i] - i) >= (i - left.top().second)) near[i] = left.top().second;
        }
        left.push({build[i], i});
    }

    for(int i=1; i<=n; i++) {
        if(cnt[i] == 0) cout<< 0 <<'\n';
        else cout<<cnt[i]<<" "<<near[i]<<'\n';
    }
}