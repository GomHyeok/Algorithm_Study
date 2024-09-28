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

int Rpoint() {//) 가 더 많은 경우
    //앞에서 부터 ( 스택에 넣고 어느 인덱스에서 문제인지 확인함
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

int LPoint() {//( 가 더 많은 경우
    //뒤에서 부터 )를 스택에 넣고 어느 지점이 문제인지 확인함
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

    //괄호의 개수가 홀수개면 무조건 이상한 괄호임
    if(input.length() % 2) {
        cout<<0<<endl;
        return 0;
    }

    //)과 (구분하여 인덱스 값 저장
    for(int i=0; i<input.size(); i++) {
        if(input[i] == ')') rights.push_back(i);
        else lefts.push_back(i);
    }

    int dif = rights.size() - lefts.size();
    if(dif == -2) { // '(' 가 더 많은 경우
        int pos = LPoint();
        //확인된 지점 부터 뒷부분의 ( 개수 
        for(int i=lefts.size()-1 ; i>=0; i--) {
            answer++;
            if(pos == lefts[i]) break;
        }
    } else if(dif == 2) {
        int pos = Rpoint();
        //확인된 지점 부터 앞부분의 ) 개수
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
