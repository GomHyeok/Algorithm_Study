#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int n;
int number[101];
bool visited[101];
set<int> answer;
bool possible;

void dfs(int first, int second);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>number[i];
    }

    for(int i=1; i<=n; i++) {
        visited[i] = true;
        dfs(i, number[i]);
        memset(visited, false, 101);
        possible = false;
    }
    cout<<answer.size()<<endl;
    for(auto iter : answer) {
        cout<<iter<<endl;
    }

}

void dfs(int first, int second) {
    if(visited[second]) {
        if(first == second) {
            possible = true;
            answer.insert(second);
        }
        return;
    }

    visited[second] = true;
    dfs(first, number[second]);
    if(possible) {
        answer.insert(first);
        answer.insert(second);
    }
}
