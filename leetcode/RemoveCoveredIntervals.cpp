#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 bool compare(vector<int> a, vector<int> b) {
    if(a[0] > b[0]) return false;
    else if (a[0] == b[0] && a[1] < b[1]) return false;

    return true;
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        vector<bool> check(intervals.size(), false);
        int cnt = 0;

        for(int i=0; i<intervals.size(); i++) {
            if(check[i]) continue;
            for(int j=i+1; j<intervals.size(); j++) {
                if(check[j]) continue;
                if(intervals[i][1] >= intervals[j][1]) {
                    cnt++;
                    check[j] = true;
                }
            }
        }
        return intervals.size() - cnt;
    }
};

int main() {
    vector<vector<int>> input = {{34335,39239},{15875,91969},{29673,66453},{53548,69161},{40618,93111}};

    cout<<Solution().removeCoveredIntervals(input)<<endl;
}