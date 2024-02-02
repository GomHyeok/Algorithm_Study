#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,k;
int answer = 999999;
bool visited[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<pair<int, int>, vector<int>>> q;
    vector<int> begin;
    cin>>n>>k;

    if(n==k) {
        cout<<0<<endl;
        cout<<n<<endl;
    }
    else if(n < k) {
        q.push({{n, 0}, begin});

        while(!q.empty()) {
            int pos = q.front().first.first;
            int time = q.front().first.second;

            if(pos == k) {
                if(time < answer) {
                    vector<int> tmp = q.front().second;
                    answer = time;
                    for(int i=0; i<tmp.size(); i++) {
                        begin.push_back(tmp[i]);
                    }
                    break;
                }
                q.pop();
            }

            if(pos * 2 <= 200000 && !visited[pos*2]) {
                vector<int> tmp = q.front().second;
                tmp.push_back(pos*2);
                q.push({{pos*2, time + 1}, tmp});
                visited[pos*2] = true;
            }
            if(pos+1 <=100000 && !visited[pos + 1]) {
                vector<int> tmp = q.front().second;
                tmp.push_back(pos + 1);
                q.push({{pos+1, time+1}, tmp});
                visited[pos+1] = true;
            }
            if(pos-1 > 0 && !visited[pos-1]) {
                vector<int> tmp = q.front().second;
                tmp.push_back(pos - 1);
                q.push({{pos-1, time+1}, tmp});
                visited[pos-1] = true;
            }

            q.pop();
        }

        cout<<answer<<endl;
        cout<<n<<" ";
        for(int i=0; i<begin.size(); i++) {
            cout<<begin[i]<<" ";
        }
        cout<<endl;
    }
    else {
        int cnt = 0;
        while(n!=k) {
            begin.push_back(n);
            n--;
            cnt++;
        }
        begin.push_back(k);
        cout<<cnt<<endl;
        for(int i=0; i<begin.size(); i++) {
            cout<<begin[i]<<" ";
        }
        cout<<endl;
    }
}