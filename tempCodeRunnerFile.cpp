#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n, m;
int l, k;
int answer;
int board[500000][500000];
int count[500000][500000];
vector<pair<int, int>> stars;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>l>>k;

    for(int i=0; i<k; i++) {
        int x, y;
        cin>>x>>y;
        stars.push_back({x, y});
        board[x][y] = 1;
    }

    // for(int i=0; i<l; i++) {
    //     for(int j=0; j<l; j++) {
    //         if(board[i][j] == 1) {
    //             answer++;
    //         }
    //     }
    // }

    // for(int i=0; i<n-l; i++) {
        
    // }

}