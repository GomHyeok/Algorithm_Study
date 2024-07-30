#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define INF 99999999

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<pair<int, int>>> edges;
vector<vector<pair<int, int>>> combackEdges;
vector<int> nodes;

int visited[700];
int dijkstraDist[700];
int n;

int dijkstra(int s) {
    for(int i=0; i<n; i++) dijkstraDist[i] = INF;
    memset(visited, 0, sizeof(visited));
    dijkstraDist[s] = 0;
    pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
    pq.push({0, s});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(visited[now] || dijkstraDist[now] < cost) continue;
        visited[now] = true;

        for(int i=0; i<edges[now].size(); i++) {
            if (dijkstraDist[edges[now][i].first] > cost + edges[now][i].second) {
                dijkstraDist[edges[now][i].first] = cost + edges[now][i].second;
                pq.push({dijkstraDist[edges[now][i].first] , edges[now][i].first});
            }
        }
    }

    long long sum = 0;
    for(int i=0; i<n; i++) {
        sum += dijkstraDist[i];
    }

    return sum;
}

int ReDijkstra(int s) {
    for(int i=0; i<n; i++) dijkstraDist[i] = INF;
    memset(visited, 0, sizeof(visited));
    dijkstraDist[s] = 0;
    pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
    pq.push({0, s});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(visited[now] || dijkstraDist[now] < cost) continue;
        visited[now] = true;

        for(int i=0; i<combackEdges[now].size(); i++) {
            if (dijkstraDist[combackEdges[now][i].first] > cost + combackEdges[now][i].second) {
                dijkstraDist[combackEdges[now][i].first] = cost + combackEdges[now][i].second;
                pq.push({dijkstraDist[combackEdges[now][i].first] , combackEdges[now][i].first});
            }
        }
    }

    long long sum = 0;
    for(int i=0; i<n; i++) {
        sum += dijkstraDist[i];
    }

    return sum;
}

int init(int N, int sCity[], int eCity[], int mCost[]) {
    nodes.clear();
    n = N;
    for(int i=0; i<N; i++) {
        nodes.push_back(sCity[i]);
        nodes.push_back(eCity[i]);
    }

    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    n = nodes.size();

    edges.clear();
    edges.resize(n + 1);
    combackEdges.clear();
    combackEdges.resize(n+1);

    for(int i=0; i<N; i++) {
        edges[lower_bound(nodes.begin(), nodes.end(), sCity[i]) - nodes.begin()].push_back({lower_bound(nodes.begin(), nodes.end(), eCity[i])-nodes.begin(), mCost[i]});
        combackEdges[lower_bound(nodes.begin(), nodes.end(), eCity[i]) - nodes.begin()].push_back({lower_bound(nodes.begin(), nodes.end(), sCity[i])-nodes.begin(), mCost[i]});
    }

	return n;
}

void add(int sCity, int eCity, int mCost) {
	edges[lower_bound(nodes.begin(), nodes.end(), sCity) - nodes.begin()].push_back({lower_bound(nodes.begin(), nodes.end(), eCity)-nodes.begin(), mCost});
    combackEdges[lower_bound(nodes.begin(), nodes.end(), eCity) - nodes.begin()].push_back({lower_bound(nodes.begin(), nodes.end(), sCity)-nodes.begin(), mCost});
}

int cost(int mHub) {
	return dijkstra(lower_bound(nodes.begin(), nodes.end(), mHub) - nodes.begin())
    +ReDijkstra(lower_bound(nodes.begin(), nodes.end(), mHub) - nodes.begin());
}