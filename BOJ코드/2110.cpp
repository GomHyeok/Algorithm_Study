#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n, c;
int answer;
vector<long long> house;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>c;

    for(int i=0; i<n; i++) {
        long long num;
        cin>>num;
        house.push_back(num);
    }

    sort(house.begin(), house.end());

    int minDist = 1;
    int maxDist = house[n-1] - house[0];

    while(minDist <= maxDist) {
        int midDist = (minDist + maxDist)/2;

        //cout<<minDist<<" "<<maxDist<<" "<<midDist<<endl;

        int cnt = 1;
        int prev = house[0];
        for(int i=1; i<n; i++) {
            if(house[i] - prev >= midDist) {
                cnt++;
                prev = house[i];
            }
        }

        if(cnt >= c) {
            answer = max(answer, midDist);
            minDist = midDist + 1;
        }
        else maxDist = midDist -1;
    }

    cout<<answer<<endl;

}