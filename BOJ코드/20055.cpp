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
        //가장 처음 수행되는 단계 1단계
        answer++;
        //컨베이어 벨트 이동
        in--;
        out--;
        if(in == 0) in = 2*n;
        if(out == 0) out = 2*n;

        //벨트위 로봇 개수
        int Robot = robot.size();

        for(int i=0; i<Robot; i++) {
            int now = robot.front();
            robot.pop();

            //로봇 한칸 이동하겠다 -> 근데 나가는 곳이면 그냥 나감
            on[now] = false;
            if(now == out) continue;

            //이동 -> 이동 조건 확인하면 이동
            int next = now+1;
            if(next > 2*n) next = 1;
            if(belt[next] >= 1 && !on[next]) {
                belt[next]--;
                if(belt[next] == 0) cnt++;
                if(next == out) continue; //이동한 곳이 out이면 나감
                on[next] = true;//이동한 경우
                robot.push(next);
            }
            else { //이동할 수 없는 경우
                on[now] = true;
                robot.push(now);
            }
        }

        //올릴 수 있는 경우
        if(!on[in] && belt[in] >= 1) {
            on[in] = true;
            belt[in]--;
            robot.push(in);
            if(belt[in] == 0) cnt++;
        }
        //종료조건
        if(cnt >= k) break;
    }

    cout<<answer<<endl;

}