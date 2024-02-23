#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

vector<deque<int>> gear(5);
int k;
int answer;
int change[5];
bool check[5];

void setting(int g, int d ) {
    change[g] = d;
    check[g] = true;
    if(g-1 >0 && !check[g-1]) {
        if(d == 0) {
            setting(g-1, 0);
        }
        else if(gear[g][6] == gear[g-1][2]) 
            setting(g-1, 0);
        else
            setting(g-1, -d);
    }

    if(g+1 <= 4 && !check[g+1]) {
        if(d == 0) {
            setting(g+1, 0);
        }
        else if(gear[g][2] == gear[g+1][6]) 
            setting(g+1, 0);
        else
            setting(g+1, -d);
    }
}

void make_change() {
    for (int i = 1; i <= 4; i++)
    {
        if (change[i] == 0)
            continue;
        if (change[i] == 1)
        {
            int temp = gear[i].back();
            gear[i].pop_back();
            gear[i].push_front(temp);
        }
        // 반시계 회전
        else
        {
            int temp = gear[i].front();
            gear[i].pop_front();
            gear[i].push_back(temp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    stack<pair<int, int>> st;
    stack<pair<int, int>> st2;
    int cnt = 1;

    for(int i=1; i<=4; i++) {
        string s;
        cin>>s;
        for(int j=1; j <= 8; j++) {
            gear[i].push_back(s[j-1] - '0');
        }
    }

    cin>>k;

    for(int i=0; i<k; i++) {
        int g, d;
        cin>>g>>d;
        memset(check, false, sizeof(check));
        setting(g, d);
        make_change();
    }

    for(int i=1; i<=4; i++) {
        if(gear[i][0] == 1) {
            answer += cnt;
        }
        cnt*=2;
    }

    cout<<answer<<endl;
}