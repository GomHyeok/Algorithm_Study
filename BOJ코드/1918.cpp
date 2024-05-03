#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

string expression;
string answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int pos = 0;

    stack<pair<char, int>> st;

    cin>>expression;

    for(int i=0; i<expression.size(); i++) {
        cout<<answer<<" "<<expression[i]<<endl;
        if(expression[i] == '(') {
            pos = 0;
        } else if(expression[i] == ')') {
            while(st.top().second != 0) {
                answer += st.top().first;
                st.pop();
            }
            answer = answer + st.top().first;
            st.pop();
            pos = st.top().second + 1;
        } else if(expression[i] >= 'A' && expression[i] <= 'Z') {
            answer = answer + expression[i];
        } else {
            if(expression[i] == '*' || expression[i] == '/') {
                while(st.top().first != '*' && st.top().first != '/'){
                    
                }
            }
            st.push({expression[i], pos});
            pos++;
        }
    }

    while(!st.empty()) {
        answer = answer + st.top().first;
        st.pop();
    }

    cout<<answer<<endl;
}