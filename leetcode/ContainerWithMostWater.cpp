#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> height;
int n;
long long answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        int h;
        cin>>h;
        height.push_back({i,h});
    }

    int left = 0;
    int right = n-1;

    while(left < right) {
        int w = abs(height[left].first - height[right].first);
        int h = min(height[left].second, height[right].second);
        long long value = w*h;

        if(value >= answer) answer = value;

        if(height[left].second > height[right].second) right--;
        else left++;
    }

    cout<<answer<<endl;
}