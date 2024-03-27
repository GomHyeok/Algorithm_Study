#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int test_case;
int a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>test_case;

    while(test_case > 0) {
        cin>>a>>b;
        vector<int> dp(10000, 0);
        vector<string> path(10000, "");
        queue<int> q;
        q.push(a);

        while(!q.empty()){
            int now = q.front();
            int s1, s2, s3, s4;

            q.pop();

            if(now == b) {
                cout<<path[b]<<"\n";
                break;
            }

            s1 = now % 10;
            s2 = (now % 100 - s1) / 10;
            s3 = (now % 1000 - now % 100) / 100;
            s4 = (now - now % 1000) / 1000;

            for(int i=0; i<4; i++) {
                if(i == 0) {
                    int value = now * 2;
                    if(value > 9999) value %= 10000;

                    if(value == a) {
                        dp[value] = 1;
                        continue;
                    }
                    if(dp[value] != 0) continue;

                    dp[value] = dp[now] + 1;
                    path[value] = path[now] + "D";
                    q.push(value);
                } else if(i == 1) {
                    int value = now-1;
                    if(value < 0) value = 9999;

                    if(dp[value] != 0) continue;

                    dp[value] = dp[now] + 1;
                    path[value] = path[now] + "S";
                    q.push(value);
                } else if(i == 2) {
                    int value = ((s3*10 + s2)*10 + s1)*10 + s4;

                    if(value == a) {
                        dp[value] = 1;
                        continue;
                    }
                    if(dp[value] != 0) continue;

                    dp[value] = dp[now] + 1;
                    path[value] = path[now] + "L";
                    q.push(value);
                } else if(i == 3){
                    int value = ((s1*10 + s4)*10 + s3)*10 + s2;

                    if(value == a) {
                        dp[value] = 1;
                        continue;
                    }
                    if(dp[value] != 0) continue;

                    dp[value] = dp[now] + 1;
                    path[value] = path[now] + "R";
                    q.push(value);
                }
            }
        }

        test_case--;
    }


}