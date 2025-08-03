#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n, m;
int k;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> board;
    map<string, int> count;

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        string st;
        cin>>st;
        board.push_back(st);
    }

    cin>>k;

    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(int j=0; j<m; j++) {
            if(board[i][j] == '0') cnt++;
        }

        if(cnt > k || cnt%2 != k%2) continue;

        if(count.find(board[i]) == count.end()) count[board[i]] = 1;
        else count[board[i]]++;
    }

    for(auto iter : count) {
        answer = max(iter.second,  answer);
    }

    cout<<answer<<endl;
}