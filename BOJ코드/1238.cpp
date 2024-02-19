#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX_VAL 9999999

using namespace std;

int n, m, x;
vector<pair<int, int>> load[1001];
int value[1001];
int answer;

int Dijstra(int s);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>x;

    for(int i=0; i<m; i++) {
        int s, e, t;
        cin>>s>>e>>t;
        load[s].push_back({t, e});
    }

    for(int i=1; i<=n; i++) {
        value[i] = Dijstra(i);
    }

    vector<int> dist(1001, MAX_VAL);

    dist[x] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int pos = pq.top().second;

        pq.pop();

        if(cost > dist[pos]) continue;

        for(int i=0; i < load[pos].size(); i++) {
            int visit = load[pos][i].second;
            int visit_cost = load[pos][i].first + cost;

            if(visit_cost < dist[visit]) {
                dist[visit] = visit_cost;
                pq.push({visit_cost, visit});
            }
        }
    }

    for(int i=1; i<=n; i++) {
        answer = max(answer, value[i] + dist[i]);
    }

    cout<<answer<<endl;

}

int Dijstra(int s) {
    vector<int> dist(1001, MAX_VAL);

    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int pos = pq.top().second;

        pq.pop();

        if(cost > dist[pos]) continue;

        for(int i=0; i < load[pos].size(); i++) {
            int visit = load[pos][i].second;
            int visit_cost = load[pos][i].first + cost;

            if(visit_cost < dist[visit]) {
                dist[visit] = visit_cost;
                pq.push({visit_cost, visit});
            }
        }
    }

    return dist[x];
}