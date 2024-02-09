#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool flag;
bool flagY;
string st;
vector<string> answer;

void check();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1) {
        int count = 0;
        int x = 0;
        int c = 0;
        flag = false;
        flagY = false;
        cin>>st;
        if(st == "end") break;

        for(int i=0; i<9; i++) {
            if(st[i] == '.') count++;
            else if(st[i] == 'X') x++;
            else c++;
        }

        if(c > x) {
            answer.push_back("invalid");
            continue;
        }

        check();

        if(flag && !flagY && x-c == 1) answer.push_back("valid");
        else if(!flag && flagY && x==c) answer.push_back("valid");
        else if(!flag && !flagY && x==5 && c == 4) answer.push_back("valid");
        else answer.push_back("invalid");

        
    }

    for(int i=0; i<answer.size(); i++) {
        cout<<answer[i]<<endl;
    }
}

void check() {
    int cnt = 0;
    //x가 이기는 경우

    for(int i=0; i<3; i++) {
        if(st[i*3]=='X' && st[i*3 + 1]=='X' && st[i*3 + 2]=='X') flag = true;
    }
    for(int i=0; i<3; i++) {
        if(st[i]=='X' && st[i + 3]=='X' && st[i + 6]=='X') flag = true;
    }

    if(st[0]=='X' && st[4]=='X' && st[8]=='X') flag = true;
    if(st[2]=='X' && st[4]=='X' && st[6]=='X') flag = true;

    //y가 이기는 경우
    for(int i=0; i<3; i++) {
        if(st[i*3]=='O' && st[i*3 + 1]=='O' && st[i*3 + 2]=='O') flagY = true;
    }
    for(int i=0; i<3; i++) {
        if(st[i]=='O' && st[i + 3]=='O' && st[i + 6]=='O') flagY = true;
    }

    if(st[0]=='O' && st[4]=='O' && st[8]=='O') flagY = true;
    if(st[2]=='O' && st[4]=='O' && st[6]=='O') flagY = true;
}