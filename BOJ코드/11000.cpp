#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n;
long long answer;
vector<pair<long long, long long>> classes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long endTime;
    cin>>n;

    for(int i=0; i<n; i++) {
        long long s, t;
        cin>>s>>t;
        classes.push_back({s, t});
    }

    sort(classes.begin(), classes.end());

    answer++;
    endTime = classes[0].second;

    for(int i=1; i<n; i++) {
        if(classes[i].first > endTime) answer++;
        else if(classes[i].second > endTime) endTime = classes[i].second;
    }

    cout<<answer<<endl;
}