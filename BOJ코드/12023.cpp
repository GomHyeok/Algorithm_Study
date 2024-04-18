#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> path[2001];
bool visited[20001];
int n;
int m;
int answer;

void dfs(int deepth, int now) {
    if(deepth == 4) {
        answer = 1;
        return;
    }
    for(int i=0; i<path[now].size(); i++) {
        int next = path[now][i];
        if(visited[next]) continue;
        visited[next] = true;
        dfs(deepth + 1, next);
        visited[next] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0; i<m; i++) {
        int a, b;
        cin>>a>>b;

        path[a].push_back(b);
        path[b].push_back(a);
    }

    for(int i=0; i<n; i++) {
        memset(visited, 0, n);
        visited[i] = true;
        dfs(0, i);
        if(answer) break;
    }

    cout<<answer<<endl;

}