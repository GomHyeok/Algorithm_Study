#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, k;
int cnt;
int answer;
int in, out;
vector<int> belt;
vector<int> on;
queue<int> robot;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;

    in = 1;
    out = n;

    belt.push_back(0);
    on.push_back(false);

    for(int i=1; i<=2*n; i++) {
        int k;
        cin>>k;
        belt.push_back(k);
        on.push_back(false);
    }

    while(1) {
        answer++;
        in--;
        out--;
        if(in == 0) in = 2*n;
        if(out == 0) out = 2*n;

        int Robot = robot.size();

        for(int i=0; i<Robot; i++) {
            int now = robot.front();
            robot.pop();

            on[now] = false;
            if(now == out) continue;

            int next = now+1;
            if(next > 2*n) next = 1;
            if(belt[next] >= 1 && !on[next]) {
                belt[next]--;
                if(belt[next] == 0) cnt++;
                if(next == out) continue;
                on[next] = true;
                robot.push(next);
            }
            else {
                on[now] = true;
                robot.push(now);
            }
        }

        if(!on[in] && belt[in] >= 1) {
            on[in] = true;
            belt[in]--;
            robot.push(in);
            if(belt[in] == 0) cnt++;
        }

        if(cnt >= k) break;
    }

    cout<<answer<<endl;

}