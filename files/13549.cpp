#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int visited[200001];
int answer = 999999;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<int, int>> q;

    fill(visited, visited+200001, -1);

    cin>>n>>k;

    q.push({n, 0});

    while(!q.empty()) {
        int pos = q.front().first;
        int time = q.front().second;

        //cout<<pos<<" "<<time<<endl;

        q.pop();

        if(pos == k) {
            if(answer > time) {
                answer = time;
                continue;
            }
        }

        visited[pos] = time;

         if(pos * 2 <= 200000 && (visited[pos*2]== -1 || visited[pos*2] > time)) {
            q.push({pos*2, time});
        }

        if(pos+1 <= 100000 && (visited[pos+1]== -1 || visited[pos+1] > time+1)) {
            q.push({pos+1, time+1});
        }

        if(pos-1 >=0 && (visited[pos-1] == -1 || visited[pos-1] > time+1)) {
            q.push({pos-1, time+1});
        }
    }    

    cout<<answer<<endl;
}