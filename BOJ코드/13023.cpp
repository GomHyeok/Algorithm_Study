#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int answer;
vector<int> path[2001];
bool visited[20001];

void dfs(int now, int depth);

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

        dfs(i, 0);

        if(answer == 1) break;
    }

    cout<<answer<<"\n";
}

void dfs(int now, int depth) {
    if(depth == 4) {
        answer = 1;
        return;
    }

    for(int i=0; i<path[now].size(); i++) {
        int next = path[now][i];
        
        if(visited[next]) continue;
        visited[next] = true;
        dfs(next, depth+1);
        visited[next] = false;
        if(answer == 1) return;
    }
}

