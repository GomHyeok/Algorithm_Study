#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

string expression;
string answer;
stack<char> operation;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>expression;

    for(int i=0; i<expression.size(); i++) {
        if(expression[i] == '(') operation.push(expression[i]);
        else if(expression[i] == '*' || expression[i] == '/') {
            while(!operation.empty() && (operation.top() == '*' || operation.top() == '/')){
                answer = answer + operation.top();
                operation.pop();
            }
            operation.push(expression[i]);
        } else if(expression[i] == '+' || expression[i] == '-') {
            while(!operation.empty() && operation.top() != '('){
                answer = answer + operation.top();
                operation.pop();
            }
            operation.push(expression[i]);
        } else if(expression[i] == ')') {
            while(!operation.empty() && operation.top() != '('){
                answer = answer + operation.top();
                operation.pop();
            }
            operation.pop();
        } else answer = answer + expression[i];
    }

    while(!operation.empty()) {
        answer = answer + operation.top();
        operation.pop();
    }

    cout<<answer<<endl;
}