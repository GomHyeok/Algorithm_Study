#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int n;
int a, b;
vector<int> answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b;

    if(a>b) {
        for(int i=1; i<=a; i++) {
            answer.push_back(i);
        }
        for(int i=b-1; i>=1; i--) {
            answer.push_back(i);
        }
    }
    else {
        for(int i=1; i<a; i++) {
            answer.push_back(i);
        }
        for(int i=b; i>=1; i--) {
            answer.push_back(i);
        }
    }

    if(answer.size() > n) {
        cout<<-1<<endl;
        return 0;
    }

    if(answer.size() < n) {
        vector<int> tmp;
        tmp.push_back(answer[0]);
        for(int i = answer.size(); i<n; i++) {
            tmp.push_back(1);
        }
        for(int i=1; i<answer.size(); i++) {
            tmp.push_back(answer[i]);
        }

        answer = tmp;
    }

    for(int i=0; i<n; i++) {
        cout<<answer[i]<<" ";
    }
    cout<<endl;

}