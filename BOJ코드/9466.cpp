#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int test_case;
int n;
int cnt;
int student[100001];
bool visited[100001];
bool checked[100001];
vector<int> answers;

void check_Cycle(int pos);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>test_case;

    while(test_case > 0) {
        cnt = 0;
        cin>>n;
        for(int i=1; i<=n; i++) {
            cin>>student[i];
            visited[i] = false;
            checked[i] = false;
        }

        for(int i=1; i<=n; i++) {
            if(visited[i]) continue;
            check_Cycle(i);
        }
        
        answers.push_back(n-cnt);
        test_case--;
    }

    for(int i=0; i<answers.size(); i++) {
        cout<<answers[i]<<"\n";
    }
}

void check_Cycle(int pos) {
    visited[pos] = true;
    int next = student[pos];

    if(!visited[next]) {
        check_Cycle(next);
    } else if(!checked[next]) {
        for(int i=next; i!=pos; i = student[i]){
            cnt++;
        }
        cnt++;
    }
    checked[pos] = true;
}
