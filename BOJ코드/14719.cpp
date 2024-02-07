#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int h,w;
int left_wall;
int right_wall;
int answer;
vector<pair<int, int>> wall_pair;
vector<int> wall;
bool visited[500];

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second > b.second) return true;
    else if(a.second == b.second) {
        if(a.first < b.first) return true;
        else return false;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>h>>w;

    for(int i=0; i<w; i++) {
        int n;
        cin>>n;
        wall_pair.push_back({i, n});
        wall.push_back(n);
    }

    sort(wall_pair.begin(), wall_pair.end(), compare);

    left_wall = wall_pair[0].first;
    right_wall = wall_pair[0].first;

    visited[left_wall] = true;

    for(int i=1; i<wall.size(); i++) {
        int pos = wall_pair[i].first;
        int value = wall_pair[i].second;

        if(visited[pos]) continue;

        visited[pos] = true;

        if(pos > right_wall) {
            for(int j=right_wall + 1; j<pos; j++) {
                answer += (wall[pos] - wall[j]);
                visited[j] = true;
            }
            right_wall = pos;
        }

        if(pos < left_wall) {
            for(int j=pos; j<left_wall; j++) {
                answer += (wall[pos] - wall[j]);
                visited[j] = true;
            }
            left_wall = pos;
        }
    }

    cout<<answer<<endl;

}