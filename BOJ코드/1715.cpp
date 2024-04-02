#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n;
long long answer;
priority_queue<int, vector<int>, greater<int>> cards;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        int card;
        cin>>card;
        cards.push(card);
    }

    while(cards.size() > 1) {
        long long card1 = cards.top();
        cards.pop();
        long long card2 = cards.top();
        cards.pop();
        answer += card1 + card2;
        cards.push(card1 + card2);
    }

    cout<<answer<<endl;

}