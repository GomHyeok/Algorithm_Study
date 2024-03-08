#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int idx = 0;
    int ep = -1;
    sort(targets.begin(), targets.end());
    
    while(idx < targets.size()) {
        int ep = targets[idx][1];
        idx++;
        answer++;
        while(idx < targets.size() && targets[idx][0] < ep) {
            if(targets[idx][1] < ep) ep = targets[idx][1];
            idx++;
        }
    }
    
    return answer;
}