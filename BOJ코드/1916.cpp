#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n, m;
int start, finish;
vector<pair<int, int>> path[1002];
vector<int> dijksra(1002, 99999999);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    cin>>n>>m;

    path[0].push_back({0,0});
    for(int i=0; i<m; i++) {
        int s, e, v;
        cin>>s>>e>>v;
        path[s].push_back({e, v});
    }

    cin>>start>>finish;

    q.push({start, 0});
    dijksra[start] = 0;

    while(!q.empty()) {
        int pos = q.top().first;
        int value = q.top().second;
        q.pop();

        if(dijksra[pos] < value) continue;

        for(int i=0; i<path[pos].size(); i++) {
            int next = path[pos][i].first;
            int cost = path[pos][i].second;

            if(dijksra[next] > cost + value) {
                dijksra[next] = cost+value;
                q.push({next, dijksra[next]});
            }
        }
    }

    cout<<dijksra[finish]<<"\n";

}