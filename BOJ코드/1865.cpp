#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#define INF 987654321

using namespace std;

int test_case;
int n, m, w;

struct node {
    int s;
    int e;
    int t;
};

bool check(vector<node> nodes);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>> test_case;

    for(int i=0; i<test_case; i++) {
        cin>>n>>m>>w;

        vector<node> nodes;

        for(int i=0; i<m; i++) {
            int s, e, t;
            cin>>s>>e>>t;

            nodes.push_back({s, e, t});
            nodes.push_back({e, s, t});
        }

        for(int i=0; i<w; i++) {
            int s, e, t;
            cin>>s>>e>>t;
            nodes.push_back({s, e, -t});
        }

        if(check(nodes)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }

}

bool check(vector<node> nodes) {
    vector<int> dist(n+1, INF);

    int s, e, t;
    dist[1] = 0;
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<nodes.size(); j++) {
            s = nodes[j].s;
            e = nodes[j].e;
            t = nodes[j].t;

            if(dist[e] > dist[s] + t) dist[e] = dist[s] + t;
        }
    }

    for(int i=0; i<nodes.size(); i++) {
        s = nodes[i].s;
        e = nodes[i].e;
        t = nodes[i].t;

        if(dist[e] > dist[s] + t) return true;
    }

    return false;
}