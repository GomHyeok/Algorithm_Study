#include <algorithm>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

int n;
long long ans = 99999999;
map<string, int> check;
string answer;
string now;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>now;
    cin>>answer;

    string tmp = now;
    long long cnt = 0;

    tmp[0] = (tmp[0] == '0') ? '1' : '0';
    tmp[1] = (tmp[1] == '0') ? '1' : '0';

    cnt++;

    for(int i=1; i<n; i++) {
        if(tmp[i-1] != answer[i-1]) {
            cnt++;
            tmp[i-1] = (tmp[i-1] == '0') ? '1' : '0';
            tmp[i] = (tmp[i] == '0') ? '1' : '0';
            if(i+1 <= n-1) tmp[i+1] = (tmp[i+1] == '0') ? '1' : '0';
        }
    }
    
    if(answer==tmp && ans > cnt) ans = cnt;

    tmp = now;
    cnt = 0;

    for(int i=1; i<n; i++) {
        if(tmp[i-1] != answer[i-1]) {
            cnt++;
            tmp[i-1] = (tmp[i-1] == '0') ? '1' : '0';
            tmp[i] = (tmp[i] == '0') ? '1' : '0';
            if(i+1 <= n-1) tmp[i+1] = (tmp[i+1] == '0') ? '1' : '0';
        }
    }

    if(answer==tmp && ans > cnt) ans = cnt;

    if(ans == 99999999) cout<<-1<<endl;
    else cout<<ans<<endl;
}