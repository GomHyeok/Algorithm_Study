#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX_VAL 999999999

using namespace std;

int n, m;
int answer = MAX_VAL;
int board[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>board[i][j];
            if(board[i][j] == 1) house.push_back({i, j});
            else if(board[i][j] == 2) chicken.push_back({i, j});
        }
    }

    vector<bool> permutation(chicken.size(), false);
    for(int i=0; i<m; i++) permutation[i] = true;
    sort(permutation.begin(), permutation.end());

    do {
        int result = 0;

        for(int i=0; i<house.size(); i++) {
            int dist = MAX_VAL;
            for(int j=0; j<chicken.size(); j++) {
                if(!permutation[j]) continue;
                int tmp = abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second);
                if(tmp < dist) dist = tmp;
            }
            result += dist;
        }

        if(answer > result) answer = result;
    } while(next_permutation(permutation.begin(), permutation.end()));

    cout<<answer<<"\n";
}