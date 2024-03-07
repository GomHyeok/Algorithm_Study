#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<long long> y;
    long long x = 0;
    
    while(k!=1) {
        y.push_back(k);
        x++;
        if(k%2 != 0) {
            k *= 3;
            k++;
        }else {
            k /= 2;
        }
    }
    y.push_back(1);
    
    for(int i=0; i<ranges.size(); i++) {
        int start = ranges[i][0];
        int end = x + ranges[i][1];
        long long sum = 0;
        if(end > x || end < start) {
            answer.push_back(-1.0);
        } else {
            for(int j=start; j<end; j++) {
                sum += y[j];
                sum += y[j+1];
            }
            answer.push_back(sum  / 2.0);
        }
        //cout<<start<<" "<<end<<" "<<sum<<endl;
    }
    
    return answer;
}