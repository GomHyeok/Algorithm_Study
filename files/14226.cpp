#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool visited[2001][2001];
int s;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<pair<int, int>, int>> q;

    cin>>s;

    q.push({{1, 0}, 0});

    visited[1][0] = true;

    while(!q.empty()) {
        int num = q.front().first.first;
        int time = q.front().first.second;
        int clips = q.front().second;

        q.pop();

        if(num == s) {
            answer = time;
            break;
        }

        if(num <= 1000 && !visited[num][num]) {
            q.push({{num, time+1}, num});
            visited[num][num] = true;
        }

        if(clips<=1000 && num+clips<=2000 && !visited[num+clips][clips]) {
            q.push({{num+clips, time+1}, clips});
            visited[num+clips][clips] = true;
        }

        if(num-1 >=0 && !visited[num-1][clips]) {
            q.push({{num-1, time+1}, clips});
            visited[num-1][clips] = true;
        }
    }

    cout<<answer<<endl;
}