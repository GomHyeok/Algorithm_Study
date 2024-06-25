#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int n;
long long dp[11][11][11][11][11][7][7];
long long bolls[6];
long long answer;

long long dfs(int back, int cur, int a, int b, int c, int d, int e) {
    if(a==0&&b==0&&c==0&&d==0&&e==0) return 1;
    long long now = dp[a][b][c][d][e][back][cur];
    if(now != -1) return now;

    now = 0;

    if(a>0 && back!=0 && cur!=0) now+=dfs(cur,0,a-1,b,c,d,e);
    if(b>0 && back!=1 && cur!=1) now+=dfs(cur,1,a,b-1,c,d,e);
    if(c>0 && back!=2 && cur!=2) now+=dfs(cur,2,a,b,c-1,d,e);
    if(d>0 && back!=3 && cur!=3) now+=dfs(cur,3,a,b,c,d-1,e);
    if(e>0 && back!=4 && cur!=4) now+=dfs(cur,4,a,b,c,d,e-1);
    dp[a][b][c][d][e][back][cur] = now;
    return now;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) cin>>bolls[i];
    memset(dp, -1, sizeof(dp));

    //back은 없는 값, cur도 초기는 없는 값
    answer = dfs(6, 5, bolls[0], bolls[1], bolls[2], bolls[3], bolls[4]);

    cout<<answer<<endl;
}