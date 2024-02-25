#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int test_case;
int n;
vector<string> answer;
bool visited[101];

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if(a.second > b.second) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>test_case;

    while(test_case--) {
        pair<int, int> house;
        vector<pair<int, int>> store;
        queue<pair<int, int>> q;
        cin>>n;
        memset(visited, false, 101);

        cin>>house.first>>house.second;

        for(int i=0; i<=n; i++) {
            int x, y;
            cin>>x>>y;
            store.push_back({x, y});
        }

        q.push({house.first, house.second});

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;

            if(x == store[n].first && y == store[n].second) {
                answer.push_back("happy");
                break;
            }

            q.pop();

            for(int i=0; i<=n; i++) {
                int dist = abs(x - store[i].first) + abs(y - store[i].second);
                if(dist <= 1000 && !visited[i]) {
                    visited[i] = true;
                    q.push({store[i].first, store[i].second});
                }
            }
        }

        if(!visited[n]) {
            answer.push_back("sad");
        }
    }

    for(int i=0; i<answer.size(); i++) {
        cout<<answer[i]<<endl;
    }
}