#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack<int> st;
    int x, y;

    cin>>n;

    for(int i=0; i<=n; i++) {
        if(i == n) y=0;
        else cin>>x>>y;
        while(!st.empty() && st.top() >= y) {
            if(st.top() == y) {
                st.pop();
                continue;
            }
            answer++;
            st.pop();
        }
        st.push(y);
    }

    cout<<answer<<endl;

}