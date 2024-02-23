#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int n, l;
int answer;
int board[100][100];
int board2[100][100];

void checking(int road[100][100]) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>board[i][j];
            board2[j][i] = board[i][j];
        }
    }

    

    cout<<answer<<endl;

}