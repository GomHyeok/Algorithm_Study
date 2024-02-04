#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n, m;
int l, k;
int answer;
vector<pair<int, int>> stars;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>l>>k;

    for(int i=0; i<k; i++) {
        int x, y;
        cin>>x>>y;
        stars.push_back({x, y});
    }

    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            int cnt = 0;
            int x = stars[i].first;
            int y = stars[j].second;
            for(int a = 0; a<k; a++) {
                int nx = stars[a].first;
                int ny = stars[a].second;
                if(x<=nx && x+l >= nx && y <= ny && y+l >= ny) cnt++;
            }
            if(answer<cnt) answer = cnt;
        }
    }

    cout<<k-answer<<endl;
}