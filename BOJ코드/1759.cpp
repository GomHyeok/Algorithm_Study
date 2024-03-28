#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int l, c;
vector<char> alpa;
vector<bool> input;
vector<string> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>l>>c;

    for(int i=0; i<c; i++) {
        char ch;
        cin>>ch;
        alpa.push_back(ch);
        input.push_back(false);
    }

    for(int i=0; i<l; i++) {
        input[i] = true;
    }

    sort(alpa.begin(), alpa.end());
    sort(input.begin(), input.end());

    do{
        string st = "";
        int gather = 0;
        int constant = 0;
        for(int i=0; i<input.size(); i++) {
            if(input[i]) {
                st += alpa[i];
                if(alpa[i] == 'a' || alpa[i] == 'e' || alpa[i] == 'i' || alpa[i] == 'o' || alpa[i] =='u') {
                    gather++;
                } else constant++;
            }
        }
        if(gather >= 1 && constant >= 2) answer.push_back(st);
    } while(next_permutation(input.begin(), input.end()));

    sort(answer.begin(), answer.end());
    
    for(int i=0; i<answer.size(); i++) {
        cout<<answer[i]<<"\n";
    }
}