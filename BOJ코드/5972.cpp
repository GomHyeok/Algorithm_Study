#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 999999999

using namespace std;

int n, m;
vector<long long> dist(50000, INF);
int answer = INF;
vector<vector<pair<int, int>>> weight(50000);

void dfs(int pos, int dist);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > pq;

    cin>>n>>m;

    for(int i=0; i<m; i++) {
        int x, y, value;
        cin>>x>>y>>value;
        weight[x-1].push_back({y-1, value});
        weight[y-1].push_back({x-1, value});
    }

    dist[0] = 0;

    pq.push({0, 0});

    while(!pq.empty()) {
        int x = pq.top().second;
        long long cost = pq.top().first;

        pq.pop();

        if(dist[x] < cost) continue;

        for(int i=0; i<weight[x].size(); i++) {
            int nx = weight[x][i].first;
            long long ncost = weight[x][i].second;

            if(dist[nx] > dist[x] + ncost) {
                dist[nx] = dist[x] + ncost;
                pq.push({dist[nx], nx});
            }
        }
    }

    cout<<dist[n-1]<<endl;

}