#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int answer = 0;
        int sizeOfGroup = 1;
        int index = 0;

        while(index < grades.size()) {
            answer++;
            sizeOfGroup++;
            index+=sizeOfGroup;
        }

        return answer;
    }
};

int main() {
    vector<int> grade;
    grade = {8, 8};

    cout<<Solution().maximumGroups(grade)<<endl;

}