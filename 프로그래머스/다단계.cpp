#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;

//나의 부모를 연결해둔 배열 필요
//자식으로 부터 받은 이득 저장하는 배열필요
//각 이득 발생시 부모까지 올라가면서 저장
//마지막에 본인이 벌어온 것  + 자식으로 부터 받은 이득 저장
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    vector<int> parent;
    map<string, int> index;
    
    index["-"] = -1;
    
    for(int i=0; i<enroll.size(); i++) {
        string name = enroll[i];
        index[name] = i;
        answer.push_back(0);
    }
    
    for(int i=0; i<referral.size(); i++) {
        string name = referral[i];
        int idx = index[name];
        parent.push_back(idx);
    }
    
    for(int i=0; i<seller.size(); i++) {
        string name = seller[i];
        int idx = index[name];
        int cost = amount[i] * 100;
        
        while(1) {
            if(idx < 0 || cost <= 0) break;
            int minus = cost / 10;
            answer[idx] += (cost - minus);
            idx = parent[idx];
            cost = minus;
        }
    }
    
    return answer;
}