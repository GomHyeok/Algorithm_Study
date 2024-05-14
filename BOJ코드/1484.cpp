#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int g;
int now, past;
vector<long long> weight;
vector<long long> answers;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>g;

    for(int i=0; i<g; i++) {
        weight.push_back((i+1));
    }

    while(now<g) {
        long long value = pow(weight[now], 2) - pow(weight[past],2);

        if(value == g) answers.push_back(weight[now]);

        if(value < g) now++;
        else past++;
    }

    if(answers.size()== 0) cout<<-1<<endl;
    else {
        for(int i=0; i<answers.size(); i++) cout<<answers[i]<<endl;
    }
}