#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n, m;
int board[15][15];
vector<int> answer;

void input();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testcase;
    cin>>testcase;

    for(int t=0; t<testcase; t++) {
        input();
    }
}

void input() {
    cin>>n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char ch;
            cin>>ch;

            if(ch == '.') board[i][j] = 0;
            else board[i][j] = 1;
        }
    }
}