#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#define MAX_VAL 10001;

using namespace std;

int n, k;
int value[10001];
int coin[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<int, int>> q;

    cin>>n>>k;

    for(int i=1; i<=k; i++) {
        value[i] = MAX_VAL;
    }

    for(int i=0; i<n; i++) {
        cin>>coin[i];
        for(int j= coin[i]; j<=k; j++) {
            value[j] = min(value[j], value[j-coin[i]] + 1);
        }
    }

    if(value[k] == 10001) cout<<-1<<endl;
    else cout<<value[k]<<endl;

}