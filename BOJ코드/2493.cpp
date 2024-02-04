#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;

vector<int> towers;
vector<int> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    answer.push_back(0);
    answer.push_back(0);
    towers.push_back(0);
    cin>>n;

    for(int i=1; i<=n; i++) {
        int a;
        cin>>a;
        towers.push_back(a);
    }

    for(int i=2; i<=n; i++) {
        int now = towers[i];
        int best = answer[i-1];

        if(now < towers[i-1]) {
            answer.push_back(i-1);
            continue;
        }

        while(best != 0) {
            if(towers[best] > now) {
                answer.push_back(best);
                break;
            }

            best = answer[best];
        }

        if(best == 0) {
            answer.push_back(0);
        }
    }

    for(int i=1; i<=n; i++) {
        cout<<answer[i]<<" ";
    }
    cout<<endl;
}