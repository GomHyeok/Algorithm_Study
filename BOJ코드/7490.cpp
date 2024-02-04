#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int test;
int num;

void solution(int sum, int now, int n, int operate, string st);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>test;

    while(test) {
        cin>>num;

        solution(0, 1, 1, 1, "1");
        cout<<endl;
        test--;
    }
}

void solution(int sum, int now, int n, int operate, string st) {
    if(n == num) {
        sum += (now * operate);
        if(sum == 0) {
            cout<<st<<endl;
        }
    } 
    else {
        solution(sum, now*10 + (n+1), n+1, operate, st + ' ' + char(n + 1 + '0'));
        solution(sum + (now *operate), n+1, n+1, 1, st + '+' + char(n + 1 + '0'));
        solution(sum + (now * operate), n+1, n+1, -1, st + '-' + char(n + 1 + '0'));
    }
}