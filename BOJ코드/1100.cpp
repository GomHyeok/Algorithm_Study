#include <iostream>
#include <vector>

using namespace std;

vector<string> board;
int answer;

int main() {
    for(int i=0; i<8; i++) {
        string st;
        cin>>st;
        board.push_back(st);
    }

    int row = 0;
    int col = 0;

    while(row < 8) {
        if(board[row][col] == 'F') answer ++;

        col += 2;
        if(col >=8) {
            row ++;
            col %= 8;
            if(row %2 == 0) col = 0;
            else col = 1;
        }
    }

    cout<<answer<<endl;
}