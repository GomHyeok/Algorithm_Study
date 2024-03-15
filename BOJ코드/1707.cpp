#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int k, v, e;
vector<string> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>k;

    while(k > 0) {
        vector<int> path[20001];
        int color[20001];

        cin>>v>>e;
        k--;
        for(int i=1; i<=v; i++) {
            color[i] = 0;
        }
        for(int i=0; i<e; i++) {
            int s, e;
            cin>>s>>e;
            path[s].push_back(e);
            path[e].push_back(s);
        }

        color[1] = 1;
        queue<int> q;
        bool flag = false;
        q.push(1);

        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for(int i=0; i< path[now].size(); i++) {
                if(color[now] == color[path[now][i]]) {
                    flag = true;
                    answer.push_back("NO");
                    break;
                } else if(color[path[now][i]] == 0) {
                    color[path[now][i]] = color[now] * -1;
                    q.push(path[now][i]);
                }
            }

            if(flag) break;
        }

        if(!flag) {
            answer.push_back("YES");
        }
    }

    for(int i=0; i< answer.size(); i++) {
        cout<<answer[i]<<"\n";
    }

}