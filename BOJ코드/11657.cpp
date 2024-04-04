#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

int n, m;
long long dist[501];
vector<pair<pair<int, int>, int>> path;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++) dist[i] = INF;
    for(int i=0; i<m; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        path.push_back({{a, b}, c});
    }

    dist[1] = 0;
    for(int i=1; i<=n-1; i++) {
        for(int j=0; j<path.size(); j++) {
            int a = path[j].first.first;
            int b = path[j].first.second;
            int cost = path[j].second;

            if(dist[a] == INF) continue;
            if(dist[b] > dist[a] + cost) dist[b] = dist[a] + cost;
        }
    }

    for(int i=0; i<path.size(); i++) {
        int a = path[i].first.first;
        int b = path[i].first.second;
        int cost = path[i].second;

        if(dist[a] == INF) continue;
        if(dist[b] > dist[a] + cost) {
            cout<<-1<<endl;
            return 0;
        }
    }

    for(int i=2; i<=n; i++) {
        if(dist[i] == INF) cout<<-1<<"\n";
        else cout<<dist[i]<<"\n";
    }

}