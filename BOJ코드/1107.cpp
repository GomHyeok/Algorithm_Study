#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int n, m;
int now = 100;
int answer;
int tmp;
bool impossible[10];

bool check(int num) {
    if(num == 0) {
        if(impossible[0]) return false;
    }
    while(num > 0) {
        if(impossible[num%10]) return false;
        num /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    answer = abs(n-now);

    for(int i=0; i<m; i++) {
        int a;
        cin>>a;
        impossible[a] = true;
    }

    for(int i=0; i<=1000000; i++) {
        if(check(i)) {
            int cnt = abs(n-i) + to_string(i).length();
            answer = min(cnt, answer);
        }
    }

    cout<<answer<<endl;

}