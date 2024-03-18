#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int n, answer;

void dfs(int cnt, vector<vector<int>> board);
vector<vector<int>> move(int k, vector<vector<int>> board);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> board;

    cin>>n;

    board.assign(n+1, vector<int>(n+1, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>board[i][j];
        }
    }

    dfs(0, board);
    cout<<answer<<"\n";

}

void dfs(int cnt, vector<vector<int>> board) {
    if(cnt == 5) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(answer < board[i][j]) answer = board[i][j];
            }
        }

        return;
    }

    for(int i=0; i<4; i++) {
        dfs(cnt + 1, move(i, board));
    }
}

vector<vector<int>> move(int k, vector<vector<int>> board){
    vector<vector<int>> tmp;
    tmp.assign(n+1, vector<int>());

    if(k == 0) {
        for(int i=0; i<n; i++) {
            bool Zero = true;
            for(int j=0; j<n; j++) {
                if(board[i][j] != 0) {
                    tmp[i].push_back(board[i][j]);
                    Zero = false;
                }
            }
            if(Zero) {
                tmp[i].push_back(0);
            }
        }
    } else if(k==1) {
        for(int i=0; i<n; i++) {
            bool Zero = true;
            for(int j=n-1; j >= 0; j--) {
                if(board[i][j] != 0) {
                    tmp[i].push_back(board[i][j]);
                    Zero = false;
                }
            }
            if(Zero) {
                tmp[i].push_back(0);
            }
        }
    } else if(k==2) {
        for(int i=0; i<n; i++) {
            bool Zero = true;
            for(int j=0; j<n; j++) {
                if(board[j][i] != 0) {
                    tmp[i].push_back(board[j][i]);
                    Zero = false;
                }
            }
            if(Zero) {
                tmp[i].push_back(0);
            }
        }
    } else if(k==3) {
        for(int i=0; i<n; i++) {
            bool Zero = true;
            for(int j=n-1; j > 0; j--) {
                if(board[j][i] != 0) {
                    tmp[i].push_back(board[j][i]);
                    Zero = false;
                }
            }
            if(Zero) {
                tmp[i].push_back(0);
            }
        }
    }

    for(int i = 0; i < n; ++i) {
		int temp = tmp[i][0];
		for(int j = 1; j < tmp[i].size(); ++j) {
			if (tmp[i][j] == 0)
				break;
			else if (temp == tmp[i][j]) {
				tmp[i][j - 1] = temp * 2;
				vector<int>::iterator it = tmp[i].begin();
				tmp[i].erase(it + j);
				temp = tmp[i][j]; // 다음걸로 갱신
			} else {
				temp = tmp[i][j];
			}
		}
	}

	if (k == 0) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < tmp[i].size(); ++j) {
				board[i][j] = tmp[i][j];
			}
			for(int j = tmp[i].size(); j < n; ++j) {
				board[i][j] = 0;
			}
		}
	}
	else if (k == 1) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < tmp[i].size(); ++j) {
				board[i][n - 1 - j] =tmp[i][j];
			}
			for(int j = tmp[i].size(); j < n; ++j) {
				board[i][n - 1 - j] = 0;
			}
		}
	}
	else if (k == 2) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < tmp[i].size(); ++j) {
				board[j][i] = tmp[i][j];
			}
			for(int j = tmp[i].size(); j < n; ++j) {
				board[j][i] = 0;
			}
		}
	}
	else if (k == 3) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < tmp[i].size(); ++j) {
				board[n - 1 - j][i] = tmp[i][j];
			}
			for(int j = tmp[i].size(); j < n; ++j) {
				board[n - 1 - j][i] = 0;
			}
		}
	}
	return board;
}