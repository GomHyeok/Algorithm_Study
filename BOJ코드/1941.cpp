#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int board[5][5];
int answer;
vector<bool> permutate(25, false);

bool possible(vector<pair<int, int>> selected) {
    queue<int> q;
    q.push(6);
    vector<bool> visited(6, false);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i=0; i<6; i++) {
            if(visited[i]) continue;
            if(abs(selected[now].first - selected[i].first) + abs(selected[now].second - selected[i].second) == 1) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    for(int i=0; i<6; i++) {
        if(!visited[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<5; i++) {
        string st;
        cin>>st;
        for(int j=0; j<5; j++) {
            if(st[j] == 'S') board[i][j] = 1;
        }
    }

    for(int i=0; i<7; i++) permutate[i] = true;

    sort(permutate.begin(), permutate.end());

    do {
        vector<pair<int, int>> selected;
        for(int i=0; i<25; i++) {
            if(permutate[i]) selected.push_back({i/5, i%5});
        }

         if(!possible(selected)) continue;

        int cnt = 0;
        for(int i=0; i<7; i++) {
            if(board[selected[i].first][selected[i].second]) cnt++;
        }
        if(cnt >= 4) answer++;
    }while(next_permutation(permutate.begin(), permutate.end()));

    cout<<answer<<endl;

}