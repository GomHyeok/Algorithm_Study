#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e;
vector<vector<int>> input(1001, vector<int>(0));
vector<vector<int>> output(1001, vector<int>(0));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int t = 1; t<=10 ;t++) {
        vector<int> answer;
        queue<int> q;
        cin>>v>>e;

        for(int i=1; i<=v; i++) {
            input[i].clear();
            output[i].clear();
        }

        for(int i=0; i<e; i++) {
            int f, s;
            cin>>f>>s;

            input[s].push_back(f);
            output[f].push_back(s);
        }

        for(int i=1; i<=v; i++) {
            if(input[i].size() == 0) {
                q.push(i);
                answer.push_back(i);
            } 
        }

        while(!q.empty()) {
            int now = q.front();
            q.pop();

            for(int i=0; i<output[now].size(); i++) {
                int del = output[now][i];
                input[del].pop_back();
                if(input[del].size() == 0) {
                    q.push(del);
                    answer.push_back(del);
                }
            }
        }
        cout<<"#"<<t<<" ";
        for(int i=0; i<answer.size(); i++) {
            cout<<answer[i]<<" ";
        }
        cout<<endl;
    }
}