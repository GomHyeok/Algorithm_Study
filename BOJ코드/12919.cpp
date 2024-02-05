#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

string s;
string t;

void ab(string st, string ts) {
    if(st == ts) {
        cout<<1<<endl;
        exit(0);
    }

    if(st.size() >= ts.size()) return;
    if(ts[ts.size()-1] == 'A') {
        string tmp = ts;
        tmp.erase(tmp.size()-1);
        ab(st, tmp);
    }
    if(ts[0] == 'B') {
        string tmp = ts;
        tmp.erase(tmp.begin());
        reverse(tmp.begin(), tmp.end());
        ab(st, tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    cin>>t;

    ab(s, t);

    cout<<0<<endl;
    
}