#include<iostream>
#include <algorithm>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int answer = 5;
int ladder[31][11];
int n, m, h;

bool isPossible() {
    for(int i=1; i<=n; i++) {
        int col = i;
        for(int j=1; j<=h; j++) {
            if(ladder[j][col]) col++;
            else if(ladder[j][col-1]) col--;
        }

        if(col != i) return false;
    }
    return true;
}

void dfs(int max_val, int depth) {
    if(depth == max_val) {
        if(isPossible()) {
            cout<<max_val<<endl;
            exit(0);
        }

        return;
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<=h; j++) {
            if(ladder[j][i] || ladder[j][i-1] || ladder[j][i+1]) continue;

            ladder[j][i] = 1;
            dfs(max_val, depth + 1);
            ladder[j][i] = 0;

            while(!ladder[j][i-1] && !ladder[j][i+1]) j++;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>h;

    for(int i=1; i<=m; i++) {
        int a, b;
        cin>>a>>b;

        ladder[a][b] = 1;
    }

    for(int i=0; i<4; i++) {
        dfs(i, 0);
    }

    if(answer == 5) {
        cout<<-1<<endl;
    }
    else cout<<answer<<endl;
}