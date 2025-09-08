#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> spots;

//n개의 spot 사이 최대 거리
//거리 기준 = 절대값

int main() {
    cin>>n;

    for(int i=0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        spots.push_back({x, y});
    }

    
}