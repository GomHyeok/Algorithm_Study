#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test_case;
int board[100][100];
bool visited[100][100];
int dy[4] = {-1, 1};

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int t=0; t<10; t++) {
        int x, y;

        cin>>test_case;

        for(int i=0; i<100; i++) {
            for(int j=0; j<100; j++) {
                visited[i][j] = false;
                cin>>board[i][j];
                if(board[i][j] == 2) {
                    x = i;
                    y = j;
                }
            }
        }

        visited[99][99] = true;

        while(x > 0) {
            if(y + dy[0] >= 0 && y + dy[0] < 100 && !visited[x][y+dy[0]] && board[x][y+dy[0]] == 1) {
                y+=dy[0];
                visited[x][y] = true;
                continue;
            }

            if(y + dy[1] >= 0 && y + dy[1] < 100 && !visited[x][y+dy[1]] && board[x][y+dy[1]] == 1) {
                y+=dy[1];
                visited[x][y] = true;
                continue;
            }
            x--;
            visited[x][y] = true;
        }

        cout<<"#"<<test_case<<" "<<y<<endl;
    }

    return 0;

}