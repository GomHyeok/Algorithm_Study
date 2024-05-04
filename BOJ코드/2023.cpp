#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n;
vector<int> answers;

bool decimal(int num);
void dfs(int num, int cnt);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);

    for(int i=0; i<answers.size(); i++) {
        cout<<answers[i]<<endl;
    }
}

bool decimal(int num) {
    for(int i=2; i*i <= num; i++) {
        if(num % i == 0) return false;
    }

    return true;
}

void dfs(int num, int cnt) {
    if(cnt == n) {
        answers.push_back(num);
        return;
    }

    for(int i=0; i<10; i++) {
        if(decimal(num*10 + i)) dfs(num*10 + i, cnt + 1);
    }
}