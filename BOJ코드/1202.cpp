#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int n, k;
pair<int, int> jewely[300000];
vector<int> bag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int idx = 0;
    long long answer = 0;
    priority_queue<int, vector<int>> pq;

    cin>>n>>k;

    for(int i=0; i<n; i++) {
        int m, v;
        cin>>m>>v;
        jewely[i] = {m, v};
    }

    for(int i=0; i<k; i++) {
        int k;
        cin>>k;
        bag.push_back(k);
    }

    sort(bag.begin(), bag.end());
    sort(jewely, jewely+n);

    // for(int i=0; i<k; i++) {
    //     cout<<bag[i]<<" ";
    // }

    // for(int i=0; i<n; i++) {
    //     cout<<"\n"<<jewely[i].first<<" "<<jewely[i].second;
    // }

    for(int i=0; i<k; i++) {
        while(idx < n && bag[i] >= jewely[idx].first) {
            pq.push(jewely[idx].second);
            idx++;
        }
        if(!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout<<answer<<"\n";

}