#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 2000

using namespace std;

int binary[16][4] = {{0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {0,1,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,0,0},{1,0,0,1}, {1,0,1,0},{1,0,1,1}
,{1,1,0,0}, {1,1,0,1}, {1,1,1,0}, {1,1,1,1}};

int number[5][5][5];
int answer;
int n, m;
int testCase;
int board[MAX][MAX];

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>testCase;

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                number[i][j][k] = -1;
            }
        }
    }

    number[2][1][1] = 0;
    number[2][2][1] = 1;
    number[1][2][2] = 2;
    number[4][1][1] = 3;
    number[1][3][2] = 4;
    number[2][3][1] = 5;
    number[1][1][4] = 6;
    number[3][1][2] = 7;
    number[2][1][3] = 8;
    number[1][1][2] = 9;

    for(int t = 1; t<=testCase; t++) {
        int index = 7;
        int arr[8] = {0,};
        bool flag = false;
        answer = 0;

        cin>>n>>m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                char ch;
                cin>>ch;

                if(ch <= '9') ch = ch-'0';
                else ch = ch-'A'+10;

                for(int k=0; k<4; k++) {
                    board[i][j*4 + k] = binary[ch][k];
                }

            }
        }

        for(int i=1; i<n; i++) {
            for(int j=m*4-1; j>=0; j--) {
                int ratio[3] = {0,0,0};

                if(board[i][j] == 1 && board[i-1][j] == 0) {
                    while(board[i][j] == 1) {
                        ratio[2]++;
                        j--;
                    }
                    while(board[i][j] == 0) {
                        ratio[1]++;
                        j--;
                    }
                    while(board[i][j] == 1) {
                        ratio[0]++;
                        j--;
                    }

                    j++;

                    int minRatio = min(ratio[0], min(ratio[1], ratio[2]));
                    for(int k=0; k<3; k++) ratio[k] /= minRatio;

                    arr[index--] = number[ratio[0]][ratio[1]][ratio[2]];

                    if(arr[index + 1] == -1) {
                        answer = 0;
                        flag = true;
                        break;
                    }
                   
                    if(index == -1) {
                        int value = (arr[0] + arr[2] + arr[4] + arr[6]) * 3 + arr[1] + arr[3] + arr[5] + arr[7];
                        if(value % 10 == 0) {
                            for(int k=0; k<8; k++) answer += arr[k];
                        }
                        index = 7;
                    }
                    
                }
            }
            if(flag) break;
        }

        cout<<"#"<<t<<" "<<answer<<endl;
    }

    
}