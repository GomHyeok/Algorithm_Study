#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> path[32001];
int indegree[32001];
int result[32001];
int n, m;

void sorting();

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0; i<m; i++) {
        int a, b;
        cin>>a>>b;
        path[a].push_back(b);
        indegree[b]++;
    }

    sorting();
}

void sorting() {
    queue<int> q;

    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    for(int i=1; i<=n; i++) {
        if(q.empty()) return;

        int cur = q.front();
        q.pop();
        result[i] = cur;

        for(int i=0; i<path[cur].size(); i++) {
            int now = path[cur][i];
            if(--indegree[now] == 0) q.push(now);
        }
    }

    for(int i=1; i<=n; i++) {
        cout<<result[i]<<" ";
    }
    cout<<endl;
}