#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>> maxQueue;
priority_queue<int, vector<int>, greater<int>> minQueue;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        int num;
        cin>>num;

        if(maxQueue.size() == minQueue.size()) {
            maxQueue.push(num);
        } else minQueue.push(num);

        if(!maxQueue.empty() && !minQueue.empty() && maxQueue.top() > minQueue.top()) {
            int maxValue = maxQueue.top();
            int minValue = minQueue.top();
            maxQueue.pop();
            minQueue.pop();
            maxQueue.push(minValue);
            minQueue.push(maxValue);
        }
        cout<<maxQueue.top()<<"\n";
    }

}

//토양오염 관련 표