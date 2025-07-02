#include <string>
#include <vector>
#include <iostream>

using namespace std;

string answer;
bool finish;
vector<int> value;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string ds[4] = {"d", "l", "r", "u"};

void dfs(int depth, string st, int x, int y);

string solution(int n, int m, int x, int y, int r, int c, int k) {
string st = "";
int toMove = abs(r-x) + abs(c-y);
value.push_back(n);
value.push_back(m);
value.push_back(x);
value.push_back(y);
value.push_back(r);
value.push_back(c);
value.push_back(k);

//Impossible case
if(toMove > k || abs(toMove-k)%2 != 0) return "impossible";

dfs(0, st, x, y);

return answer;


}

void dfs(int depth, string st, int x, int y) {
if(finish) return;
int n = value[0];
int m = value[1];
int r = value[4];
int c = value[5];
int k = value[6];

if(k - depth < abs(x-r) + abs(y-c)) return;

if(depth == k) {
    if(x == r && y == c) {
        answer = st;
        finish = true;
    }
    return;
}

for(int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(x <= 0 || y <= 0 || x > n || y > m) continue;
    string tmp = st + ds[i];
    dfs(depth+1, tmp, nx, ny);
}

return;


}