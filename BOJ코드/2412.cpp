#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int n, t;
int answer = -1;
vector<pair<int, int> > hold;
map<pair<int, int>, bool> visited;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<pair<int, int>, int>> q;
    cin>>n>>t;

    for(int i=0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        hold.push_back({x, y});
    }

    sort(hold.begin(), hold.end(), compare);

    q.push({{0, 0}, 0});

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;

        q.pop();

        auto it = lower_bound(hold.begin(), hold.end(), pair<int,int>(0,y-2), compare) - hold.begin();

        if(y == t) {
            answer = cnt;
            break;
        }

        for(int i=it; i<hold.size(); i++) {
            int nx = hold[i].first;
            int ny = hold[i].second;

            if(abs(ny - y) > 2) break;

            if(visited[{nx, ny}]) continue;
            if(abs(nx-x) > 2) continue;
            visited[{nx, ny}] = true;
            q.push({{nx, ny}, cnt+1});
        }
    }

    cout<<answer<<endl;
}
