#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int n;
long long answer;
vector<long long> histo;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1) {
        stack<int> st;
        answer = 0;
        cin>>n;
        if(n == 0) break;

        histo.clear();

        for(int i=0; i<n; i++) {
            long long a;
            cin>>a;
            histo.push_back(a);
        }

        for(int i=0; i<n; i++) {
            while(!st.empty() && histo[i] < histo[st.top()]) {
                int idx = st.top();
                int l = i;
                long long value = histo[idx];
                st.pop();

                if(!st.empty()) l = i- st.top()-1;
                if(answer < l*value) answer = l*value;
            }

            st.push(i);
        }

        while(!st.empty()) {
            int idx = st.top();
            int l = n;
            long long value = histo[idx];
            st.pop();

            if(!st.empty()) l = n - st.top() - 1;
            if(answer < l*value) answer = l*value;
        }

        cout<<answer<<endl;
    }

}