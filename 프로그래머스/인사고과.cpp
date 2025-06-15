#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int idx = 0;
    int value = 0;
    int cnt = 0;
    
    vector<pair<int, int>> scoreSum;
    
    for(int i=0; i<scores.size(); i++) {
        int sum = scores[i][0] + scores[i][1];
        scoreSum.push_back({i, sum});
    }
    
    sort(scoreSum.begin(), scoreSum.end(), compare);
    
    for(int i=0; i<scoreSum.size(); i++) {
        if(scoreSum[i].first == 0) {
            idx = i;
            value = scoreSum[i].second;
            break;
        }
    }
    
    for(int i=idx+1; i<scoreSum.size(); i++) {
        int index = scoreSum[i].first;
        int cost = scoreSum[i].second;
        
        if(value < cost) {
            if(scores[index][0] > scores[0][0] && scores[index][1] > scores[0][1]) {
                return -1;
            }
            
            bool flag = true;
            
            for(int j=i+1; j<scoreSum.size(); j++) {
                int tmp = scoreSum[j].first;
                if(scores[index][0] < scores[tmp][0] && scores[index][1] < scores[tmp][1]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) answer++;
        }
    } 
    
    return answer;
}