#include <iostream>
#include <vector>
#include <list>
#include <cstring>

using namespace std;

list<char> note[301];
list<char>::iterator cur;
int cnt[301][26];

int h, w;
int lastR, lastC;
int nowR, nowC;

void moveLast() {
    lastC++;
    if(lastC >= w) {
        lastR++;
        lastC = 0;
    }
}

void moveNow() {
    nowC++;
    if(nowC >= w) {
        nowR++;
        nowC = 0;
        cur = note[nowR].begin();
    }
}

void printNote() {
    for(int i=0; i<=lastR; i++) {
        for(auto it : note[i]) {
            cout<<it;
        }
        cout<<endl;
    }
    cout<<"cursur : "<<*cur<<endl;
}

void init(int H, int W, char mStr[])
{
    string st = mStr;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<=H; i++) {
        note[i].clear();
    }

    h = H;
    w = W;
    nowR = 0;
    nowC = 0;

    for(int i=0; i<st.size(); i++) {
        int row = i/w;
        note[row].push_back(st[i]);
        cnt[row][st[i]-'a']++;
    }

    cur = note[0].begin();
    lastR = (st.size()-1) / w;
    lastC = (st.size()-1) % w;

}

//커서 위치에 문자 삽입
void insert(char mChar)
{
    note[nowR].insert(cur, mChar);

    cnt[nowR][mChar - 'a']++;

    int tmp = nowR;
    while(note[tmp].size() > w && tmp <=h) {
        char ch = note[tmp].back();
        note[tmp+1].push_front(ch);
        note[tmp].pop_back();
        cnt[tmp][ch-'a']--;
        cnt[tmp+1][ch-'a']++;
        tmp++;
    }

    moveLast();
    moveNow();

    // printNote();
}

//커서 위치를 변경
char moveCursor(int mRow, int mCol)
{
    int move = w*(mRow - 1) + (mCol - 1);
    if(move > w*lastR + lastC) {
        nowR = lastR;
        nowC = lastC + 1;
        if(nowC >= w) {
            nowR++;
            nowC = 0;
        }

        cur = note[nowR].end();
        //cout<<"end position"<<endl;
        // printNote();
        return '$';
    }
    
    nowR = mRow - 1;
    nowC = mCol - 1;
    cur = note[nowR].begin();
    for(int i=0; i<nowC; i++) {
        cur++;
    }

    // printNote();
	return *cur;
}

//커서 뒤쪽 부분에 특정 문자의 개수 리턴
int countCharacter(char mChar)
{
    int count = 0;
    list<char>::iterator tmp = cur;

    //if(cur == note[nowR].end()) cout<<"end"<<endl;

    while(tmp != note[nowR].end()) {
        if(*tmp == mChar) count++;
        tmp++;
    }

    for(int i=nowR+1; i<=lastR; i++) {
        count += cnt[i][mChar-'a'];
    }
    
    //printNote();
    return count;
}

