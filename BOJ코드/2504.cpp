#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int answer = 0;
int tmp = 1;
string str;
stack<char> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>str;

    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(') {
            tmp*=2;
            st.push('(');
        } else if(str[i] == '[') {
            tmp *= 3;
            st.push('[');
        } else if(str[i] == ')') {
            if(st.empty() || st.top() != '(') {
                answer = 0;
                break;
            }
            if(str[i-1] == '(') {
                answer += tmp;
                tmp /= 2;
                st.pop();
            } else {
                tmp /= 2;
                st.pop();
            }
        } else if(str[i] == ']') {
            if(st.empty() || st.top() != '[') {
                answer = 0;
                break;
            }
            if(str[i-1] == '[') {
                answer += tmp;
                tmp/=3;
                st.pop();
            } else {
                tmp /= 3;
                st.pop();
            }
        }
    }

    if(!st.empty()) answer = 0;

    cout<<answer<<"\n";
}