#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
int answer;
int cnt;
bool visited[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<int, int>> q;

    cin>>n>>k;

    q.push({n, 0});
    visited[n] = true;

    while(!q.empty()) {
        int time = q.front().second;
        int pos = q.front().first;

        q.pop();

        visited[pos] = true;

        if(cnt && pos == k && time == answer) {
            cnt++;
            continue;
        }

        if(!cnt && pos == k) {
            answer = time;
            cnt++;
            continue;
        }

        if(pos -1 >= 0 && !visited[pos-1]){
            q.push({pos-1, time+1});
        }
        if(!visited[pos+1] && pos+1 <= 100000) {
            q.push({pos+1, time+1});
        }
        if(pos*2 <= 100000 && !visited[pos*2]) {
            q.push({pos*2, time+1});
        }
    }

    cout<<answer<<endl;
    cout<<cnt<<endl;
}