#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

string input = "";
vector<int> lefts;
vector<int> rights;
int answer = 0;

//문제가 되는 지점이 기준
//해당 기준 앞쪽에 같은 모양이 변하면 올바른 문자열이 된다.
//해당 문자까지 포함되는 경우는 뒤에도 뭔가 있을때는 가능할듯
//(의 경우는 본임 포함 본인 뒤쪽 것이 변하면 가능
//)의 경우는 본인 포함 앞에 것이 변하면 가능

int Rpoint() {
    stack<int> leftPos;

    for(int i=0; i<input.size(); i++) {
         if(input[i] == ')') {
            if(leftPos.empty()) return i;
            else leftPos.pop();
         }
        else {
            leftPos.push(i);
        }
    }

    return -1;
}

int LPoint() {
    stack<int> rightPos;

    for(int i=input.size() - 1; i>=0; i--) {
         if(input[i] == '(') {
            if(rightPos.empty()) return i;
            else rightPos.pop();
         }
        else {
            rightPos.push(i);
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>input;

    if(input.length() % 2) {
        cout<<0<<endl;
        return 0;
    }


    for(int i=0; i<input.size(); i++) {
        if(input[i] == ')') rights.push_back(i);
        else lefts.push_back(i);
    }

    int dif = rights.size() - lefts.size();
    if(dif == -2) { // '(' 가 더 많은 경우
        int pos = LPoint();
        for(int i=lefts.size()-1 ; i>=0; i--) {
            answer++;
            if(pos == lefts[i]) break;
        }
    } else if(dif == 2) {
        int pos = Rpoint();
        for(int i=0; i<rights.size(); i++) {
            answer++;
            if(pos == rights[i]) break;
        }
    } else {
        cout<<0<<endl;
        return 0;
    }

    cout<<answer<<endl;
}
