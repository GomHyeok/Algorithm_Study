#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

extern void solve(int board[5][5], int pattern[3][3], int callCntLimit);

static int orgBoard[5][5];
static int orgPattern[3][3];
static int emptyY, emptyX;
static int callCnt;

bool swap(int dir) {
	int dy[4] = { -1, 0, 1, 0 };
	int dx[4] = { 0, 1, 0, -1 };

	++callCnt;

	if (dir < UP || dir > LEFT) {
		return false;
	}

	int newY = emptyY + dy[dir];
	int newX = emptyX + dx[dir];

	if (newY < 0 || newY >= 5 || newX < 0 || newX >= 5) {
		return false;
	}

	orgBoard[emptyY][emptyX] = orgBoard[newY][newX];
	orgBoard[newY][newX] = 0;
	emptyY = newY;
	emptyX = newX;

	return true;
}

static bool run() {

	int board[5][5];
	int pattern[3][3];
	int callCntLimit;

	scanf("%d", &callCntLimit);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			scanf("%d", &board[i][j]);

			orgBoard[i][j] = board[i][j];

			if (board[i][j] == 0) {
				emptyY = i;
				emptyX = j;
			}
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &pattern[i][j]);

			orgPattern[i][j] = pattern[i][j];
		}
	}

	callCnt = 0;

	solve(board, pattern, callCntLimit);

	bool isCorrect = (callCnt <= callCntLimit);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (orgBoard[i + 1][j + 1] != orgPattern[i][j]) {
				isCorrect = false;
			}
		}
	}

	return isCorrect;
}

int main(void) {

	setbuf(stdout, NULL);
	// freopen("sample_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc) {
		printf("#%d %d\n", tc, run() ? 100 : 0);
	}

	return 0;
}

#include <vector>
#include <queue>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

extern bool swap(int dir);
void findPost(int board[5][5], int pattern[3][3], int x, int y);
vector<int> findPath(int x, int y);
vector<int> findBlankPath(int x, int y);

int px;
int py;
int blankX;
int blankY;
bool visited[5][5];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void solve(int board[5][5], int pattern[3][3], int callCntLimit) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            visited[i][j] = false;
            if(board[i][j] == 0) {
                blankX = i;
                blankY = j;
            }
        }
    }

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            int now = pattern[i][j];
            int dir;
            findPost(board, pattern, i, j);
            vector<int> path = findPath(i+1, j+1);
            
            for(int k=0; k<path.size(); k++) {
                int targetX = px + dx[path[k]];
                int targetY = py + dy[path[k]];
                
                visited[px][py] = true;

                vector<int> blankPath = findBlankPath(targetX, targetY);

                // cout<<"blankPath"<<endl;


                for(int b = 0; b<blankPath.size(); b++) {
                    // cout<<blankPath[b]<<" ";
                    swap(blankPath[b]);
                    int newX = blankX + dx[blankPath[b]];
                    int newY = blankY + dy[blankPath[b]];

                    if (newY < 0 || newY >= 5 || newX < 0 || newX >= 5) continue;

                    board[blankX][blankY] = board[newX][newY];
                    board[newX][newY] = 0;
                    blankY = newY;
                    blankX = newX;
                }
                // cout<<endl;
                if(path[k] == 0) dir = 2;
                else if(path[k] == 1) dir = 3;
                else if(path[k] == 2) dir = 0;
                else if(path[k] == 3) dir = 1;
                swap(dir);
                int newX = blankX + dx[dir];
                int newY = blankY + dy[dir];

                if (newY < 0 || newY >= 5 || newX < 0 || newX >= 5) continue;

                board[blankX][blankY] = board[newX][newY];
                board[newX][newY] = 0;
                blankY = newY;
                blankX = newX;

                visited[px][py] = false;

                px = targetX;
                py = targetY;

                // for(int i=0; i<5; i++) {
                //     for(int j=0; j<5; j++) {
                //         cout<<board[i][j]<<" ";
                //     }
                //     cout<<endl;
                // }
            }
            visited[i+1][j+1] = true;
        }
    }
}

void findPost(int board[5][5], int pattern[3][3], int x, int y) {
    vector<vector<bool>> check(5, vector<bool>(5, false));

    int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
    int value = pattern[x][y];

    queue<pair<int, int>> q;


    q.push({x + 1, y + 1});

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if(board[x][y] == value) {
            px = x;
            py = y;
            return ;
        }

        check[x][y] = true;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx <0 || ny < 0 || nx >=5 || ny >=5) continue;
            if(visited[nx][ny] || check[nx][ny]) continue;

            q.push({nx, ny});
        }
    }
}

vector<int> findPath(int x, int y) {
    queue<pair<vector<int>, pair<int, int>>> q;
    vector<int> tmp;
    vector<vector<bool>> check(5, vector<bool>(5, false));

    int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

    q.push({tmp, {px, py}});

    while(!q.empty()) {
        vector<int> path = q.front().first;
        int nowX = q.front().second.first;
        int nowY = q.front().second.second;
        
        q.pop();

        if(nowX == x && nowY == y) {
            return path;
        }

        for(int i=0; i<4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if(nx <0 || ny < 0 || nx >=5 || ny >=5) continue;
            if(visited[nx][ny] || check[nx][ny]) continue;

            vector<int> tmp = path;
            tmp.push_back(i);
            q.push({ tmp ,{nx, ny}});
        }
    }

    return tmp;
}

vector<int> findBlankPath(int x, int y) {
    queue<pair<vector<int>, pair<int, int>>> q;
    vector<int> tmp;
    vector<vector<bool>> check(5, vector<bool>(5, false));

    int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

    q.push({tmp, {blankX, blankY}});

    while(!q.empty()) {
        vector<int> path = q.front().first;
        int nowX = q.front().second.first;
        int nowY = q.front().second.second;
        
        q.pop();

        if(nowX == x && nowY == y) {
            return path;
        }

        for(int i=0; i<4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if(nx <0 || ny < 0 || nx >=5 || ny >=5) continue;
            if(visited[nx][ny] || check[nx][ny]) continue;

            vector<int> tmp = path;
            tmp.push_back(i);
            q.push({ tmp ,{nx, ny}});
        }
    }
    return tmp;
}

