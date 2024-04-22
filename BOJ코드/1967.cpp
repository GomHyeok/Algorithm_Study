#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int n;
int middle;
bool visited[10001];
vector<pair<int, int>> path[10001];
long long answer;

void dfs(int node, int len);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=1; i<n; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        path[a].push_back({b,c});
        path[b].push_back({a,c});
    }

    dfs(1, 0);

    memset(visited, 0, n+1);

    dfs(middle, 0);

    cout<<answer<<endl;

}

void dfs(int node, int len) {
    if(visited[node])return;

    visited[node] = true;

    if(len > answer) {
        middle = node;
        answer = len;
    }

    for(int i=0; i<path[node].size(); i++) {
        dfs(path[node][i].first, len + path[node][i].second);
    }
}