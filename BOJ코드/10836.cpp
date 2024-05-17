#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int m, n;
vector<vector<int>> board(700, vector<int>(700, 1));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;

    for(int i=0; i<n; i++) {
        vector<int>grow;
        vector<int> row;
        vector<int> col;
        col.push_back(0);
        int zero, one, two;
        cin>>zero>>one>>two;
        
        for(int j=0; j<zero; j++) {
            grow.push_back(0);
        }
        for(int j=0; j<one; j++) {
            grow.push_back(1);
        }
        for(int j=0; j<two; j++) {
            grow.push_back(2);
        }

        for(int j=0; j<2*m-1; j++) {
            if(j < m) {
                row.push_back(grow[j]);
            } else col.push_back(grow[j]);
        }

        for(int j=0; j<m; j++) {
            board[m-1-j][0] += row[j];
        }

        for(int j=0; j<m; j++) {
            for(int k=0; k<m; k++) {
                board[j][k] += col[k];
            }
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}