#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int testCase;
string st;
int k, answer;

void dfs(int idx, int cnt) {
    if(cnt == k) {
        answer = max(stoi(st), answer);
        return;
    }

    for(int i=idx; i<st.size() - 1; i++) {
        for(int j=i+1; j<st.size(); j++) {
            swap(st[i], st[j]);
            dfs(i, cnt + 1);
            swap(st[i], st[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>testCase;

    for(int t = 1; t<=testCase; t++) {
        answer = 0;
        cin>>st>>k;

        dfs(0, 0);
        cout<<"#"<<t<<" "<<answer<<endl;
    }
}