#include <string>
#include <vector>
#define MAX_VAL 987654321

using namespace std;

bool calTime(vector<int> diffs, vector<int> times, int level, long long limit);

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int right = 0;
    int left = MAX_VAL;
    
    for(int i=0; i<diffs.size(); i++) {
        if(right < diffs[i]) right = diffs[i];
        if(left > diffs[i]) left = diffs[i];
    }
    
    while(left <= right) {
        int mid = (left + right) / 2;
        if(calTime(diffs, times, mid, limit)) {
            answer = mid;
            right = mid - 1;
        } else left = mid + 1;
    }
    
    return answer;
}

bool calTime(vector<int> diffs, vector<int> times, int level, long long limit) {
    long long result = 0;
    int prev = 0;
    for(int i=0; i<diffs.size(); i++) {
        if(level >= diffs[i]) result += times[i];
        else {
            long long sum = prev + times[i];
            result += (diffs[i] - level) * sum + times[i];
        }
        prev = times[i];
        if(result > limit) return false;
    }
    
    return true;
}