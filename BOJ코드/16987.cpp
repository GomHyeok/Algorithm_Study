#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int answer;
vector<pair<int, int>> eggs;

void dfs(int idx);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        int a, b;
        cin>>a>>b;
        eggs.push_back({a, b});
    }

    dfs(0);
    cout<<answer<<endl;
}

void dfs(int idx) {
    if(idx >= n) {
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(eggs[i].first <= 0) cnt++;
        }
        if(cnt > answer) answer = cnt;
        return;
    }

    if(eggs[idx].first <= 0) dfs(idx+1);
    else {
        bool flag = false;
        for(int i=0; i<n; i++) {
            if(idx == i || eggs[i].first <= 0) continue;

            eggs[i].first -= eggs[idx].second;
            eggs[idx].first -= eggs[i].second;
            flag = true;

            dfs(idx + 1);

            eggs[i].first += eggs[idx].second;
            eggs[idx].first += eggs[i].second;
        }

        if(!flag) dfs(n);//나머지 다 깨져있음
    }
}