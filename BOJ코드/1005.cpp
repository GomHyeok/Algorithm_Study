#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

int test_case;
int n, k, w;
map<int, int> resultCost;
map<int, int> Cost;
int degree[1003];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>test_case;

    while(test_case > 0) {
        int answer = 0;

        cin>>n>>k;
        vector<vector<int>> v(n+1);
        queue<int>q;

        for(int i=1; i<=n; i++) {
            int cost;
            cin>>cost;
            Cost[i] = cost;
            resultCost[i] = cost;
        }

        for(int i=0; i<k; i++) {
            int x, y;
            cin>>x>>y;
            v[x].emplace_back(y);
            degree[y]++;
        }

        cin>>w;

        for(int i=1; i<=n; i++) {
            if(i == w) continue;
            else if(degree[i] == 0) q.emplace(i);
        }
        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            for(int i=0; i<v[idx].size(); i++) {
                int now = v[idx][i];
                resultCost[now] = max(resultCost[now], resultCost[idx] + Cost[now]);
                if(--degree[now] == 0) q.emplace(now);
            }
        }

        cout<<resultCost[w]<<"\n";

        for(int i=1; i<=n; i++) {
            degree[i] = 0;
            resultCost[i] = 0;
            Cost[i] = 0;
        }
        test_case--;
    }

}