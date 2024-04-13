#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int v;
int deep_node;
int max_cost;
vector<pair<int, int>> path[100001];

void dfs(int cur, int prev, int cost) {
    if(cost > max_cost) {
        max_cost = cost;
        deep_node = cur;
    }

    for(int i=0; i<path[cur].size(); i++) {
        if(path[cur][i].first != prev) dfs(path[cur][i].first, cur, path[cur][i].second + cost);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int first, second, node;

    cin>>v;

    for(int i=1; i<=v; i++) {
        cin>>node;
        cin>>first;
        while(first != -1) {
            cin>>second;
            path[i].push_back({first, second});
            cin>>first;
        }
    }

    dfs(1, 0 ,0);
    max_cost = 0;
    dfs(deep_node, 0, 0);

    cout<<max_cost<<endl;
}