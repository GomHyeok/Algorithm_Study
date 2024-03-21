#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#define MAX_VAL 2000000001

using namespace std;

int n, e;
int start, finish;
long long answer;
vector<vector<pair<int, long long>>> path(801);
long long dijstra[3][801];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;

    cin>>n>>e;

    for(int i=0; i<e; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        path[a].push_back({b,c});
        path[b].push_back({a,c});
    }

    cin>>start>>finish;

    for(int i=0; i<=n; i++) {
        dijstra[0][i] = MAX_VAL;
        dijstra[1][i] = MAX_VAL;
        dijstra[2][i] = MAX_VAL;
    }

    pq.push({1, 0});
    dijstra[0][1] = 0;

    while(!pq.empty()) {
        int now = pq.top().first;
        long long cnt = pq.top().second;

        pq.pop();

        if(dijstra[0][now] < cnt) continue;

        for(int i=0; i<path[now].size(); i++) {
            int next = path[now][i].first;
            long long cost = path[now][i].second;

            if(dijstra[0][next] > dijstra[0][now] + cost) {
                dijstra[0][next] = dijstra[0][now] + cost;
                pq.push({next, dijstra[0][next]});
            }
        }
    }

    pq.push({start, 0});
    dijstra[1][start] = 0;

    while(!pq.empty()) {
        int now = pq.top().first;
        long long cnt = pq.top().second;
        
        pq.pop();

        if(dijstra[1][now] < cnt) continue;

        for(int i=0; i<path[now].size(); i++) {
            int next = path[now][i].first;
            long long cost = path[now][i].second;

            if(dijstra[1][next] > dijstra[1][now] + cost) {
                dijstra[1][next] = dijstra[1][now] + cost;
                pq.push({next, dijstra[1][next]});
            }
        }
    }

    pq.push({finish, 0});
    dijstra[2][finish] = 0;

    while(!pq.empty()) {
        int now = pq.top().first;
        long long cnt = pq.top().second;
        
        pq.pop();

        if(dijstra[2][now] < cnt) continue;

        for(int i=0; i<path[now].size(); i++) {
            int next = path[now][i].first;
            long long cost = path[now][i].second;

            if(dijstra[2][next] > dijstra[2][now] + cost) {
                dijstra[2][next] = dijstra[2][now] + cost;
                pq.push({next, dijstra[2][next]});
            }
        }
    }

    answer = dijstra[0][start] + dijstra[1][finish] + dijstra[2][n];

    if(answer > dijstra[0][finish] + dijstra[1][n] + dijstra[2][start]) {
        answer = dijstra[0][finish] + dijstra[1][n] + dijstra[2][start];
    }

    if(answer >= MAX_VAL) {
        cout<<-1<<endl;
        return 0;
    }

    cout<<answer<<endl;

}