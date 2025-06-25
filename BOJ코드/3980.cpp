#include <iostream>
#include <vector>

using namespace std;

int player[11][11];
bool visiited[11];
int answer = 0;

void dfs(int n, int sum);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testcase;
    
    cin>>testcase;

    for(int t=1; t<= testcase; t++) {
        for(int i=0; i<11; i++) {
            for(int j=0; j<11; j++) {
                cin>>player[i][j];
            }
            visiited[i] = false;
        }
        answer = 0;

        dfs(0, 0);
        cout<<answer<<endl;
    }

}

void dfs(int n, int sum) {
    if(n == 11) {
        if(sum > answer) answer = sum;
        return;
    }

    for(int i=0; i<11; i++) {
        if(player[n][i] == 0) continue;
        if(visiited[i]) continue;

        visiited[i] = true;
        dfs(n+1, sum + player[n][i]);
        visiited[i] = false;
    }
}