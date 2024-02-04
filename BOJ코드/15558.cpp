#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int k;
bool answer = false;
int left_array[200000];
int right_array[200000];
int left_visited[200000];
int right_visited[200000];


void dfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string st;

    cin>>n>>k;

    cin>>st;

    for(int i=0; i<2*n; i++) {
        left_array[i] = true;
        right_array[i] = true;
    }

    for(int i=0; i<st.length(); i++) {
        if(st[i] == '0') {
            left_array[i] = false;
        }
    }

    cin>>st;

    for(int i=0; i<st.length(); i++) {
        if(st[i] == '0') {
            right_array[i] = false;
        }
    }

    dfs();

    if(answer) {
        cout<<1<<endl;
    }
    else {
        cout<<0<<endl;
    }

    return 0;
}

void dfs() {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});

    left_visited[0] = true;

    while(!q.empty()) {
        int direct = q.front().first;
        int pos = q.front().second.first;
        int time = q.front().second.second;

        //cout<<direct<<" "<<pos<<" "<<time<<endl;

        q.pop();

        if(pos < time) continue;
        if(time >= n) break;
        if(pos >= n) {
            answer = true;
            break;
        }

        if(!direct) {
            if(left_array[pos + 1] && !left_visited[pos+1]) {
                left_visited[pos+1] = true;
                q.push({0, {pos+1, time+1}});
            }

            if(pos-1 >= 0) {
                if(left_array[pos-1] && !left_visited[pos-1]) {
                    left_visited[pos-1] = true;
                    q.push({0, {pos-1, time+1}});
                }
            }
            
            if(right_array[pos+k] && !right_visited[pos+k]) {
                right_visited[pos+k] = true;
                q.push({1, {pos+k, time+1}});
            }
        }
        else {
            if(right_array[pos + 1] && !right_visited[pos+1]) {
                right_visited[pos+1] = true;
                q.push({1, {pos+1, time+1}});
            }

            if(right_array[pos-1] && !right_visited[pos-1]) {
                right_visited[pos-1] = true;
                q.push({1, {pos-1, time+1}});
            }
            
            if(left_array[pos+k] && !left_visited[pos+k]) {
                left_visited[pos+k] = true;
                q.push({0, {pos+k, time+1}});
            }
        }
    }
}