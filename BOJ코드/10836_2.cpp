#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int m, n;
vector<vector<int>> board(700, vector<int>(700, 1));
int larva[1401];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;

    for(int i=0 ;i<n; i++) {
        int idx = 0;
        int zero, one, two;
        cin>>zero>>one>>two;

        for(int j=zero; j<zero+one; j++) larva[j]++;
        for(int j=zero+one; j<2*m-1; j++) larva[j]+=2;
    }

    for(int i=m-1; i>=0; i--) {
        cout<<larva[i] + 1<<" ";
        for(int j=m; j<2*m-1; j++) cout<<larva[j]+1<<" ";
        cout<<"\n";
    }
    
}