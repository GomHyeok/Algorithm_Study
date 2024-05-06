#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

long long dp[31][31];
vector<long long> answers;

long long dfs(int w, int h);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1) {
        int w;
        cin>>w;
        if(w == 0) break;
        answers.push_back(dfs(w, 0));
    }

    for(int i=0; i<answers.size(); i++) {
        cout<<answers[i]<<"\n";
    }
}

long long dfs(int w, int h) {
    if(h == -1) return 0;
    if(w == 0) return 1;
    if(dp[w][h]) return dp[w][h];

    long long result = dfs(w-1, h+1) + dfs(w, h-1);
    dp[w][h] = result;

    return result;
}