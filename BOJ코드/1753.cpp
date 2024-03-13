#include <iostream>
#include <vector>
#include <queue>
#define MAX_VAL 999999

using namespace std;

int v, e;
int k;
int dijkstra[20001];
vector<pair<int, int>> path[20001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    cin>>v>>e;
    cin>>k;

    for(int i=0; i<e; i++) {
        int start, end, w;
        cin>>start>>end>>w;
        path[start].push_back({end, w});
    }
    for(int i=1; i<= v; i++) {
        dijkstra[i] = MAX_VAL;
    }

    q.push({0, k});
    dijkstra[k] = 0;

    while(!q.empty()) {
        int cost = q.top().first;
        int pos = q.top().second;
        q.pop();

        for(int i=0; i<path[pos].size(); i++) {
            if(dijkstra[path[pos][i].first] >= dijkstra[pos] + path[pos][i].second) {
                dijkstra[path[pos][i].first] = dijkstra[pos] + path[pos][i].second;
                q.push({dijkstra[path[pos][i].first], path[pos][i].first});
            }
        }
    }

    for(int i=1; i<=v; i++) {
        if(dijkstra[i] == MAX_VAL) cout<<"INF"<<endl;
        else cout<<dijkstra[i]<<endl;
    }

}

