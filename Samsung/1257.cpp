#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int testCase;
int k;
string st;

struct compare {
    bool operator() (string s, string c) {
        if(s.size() > c.size()) {
            for(int i=0; i<c.size(); i++ ){
                if(c[i] > s[i]) {
                    return false;
                } else if(s[i] > c[i]) {
                    return true;
                }
            }
            return true;
        } else {
            for(int i=0; i<s.size(); i++ ){
                if(c[i] > s[i]) {
                    return false;
                } else if(s[i] > c[i] ){
                    return true;
                }
            }
            return false;
        }
    }
};

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>testCase;

    for(int t = 1; t<=testCase; t++) {
        priority_queue<string, vector<string>, compare> pq;
        map<string, int> check;
        cin>>k;
        cin>>st;

        for(int i=0; i<st.size(); i++) {
            string tmp = "";
            for(int j=i; j<st.size(); j++) {
                tmp+=st[j];
                if(check[tmp]> 0) continue;
                check[tmp] = 1;
                pq.push(tmp);
            }
        }

        if(k > pq.size()) {
            cout<<"#"<<t<<" none"<<endl;
        } else {
            string answer;
            for(int i=0; i<k; i++) {
                answer = pq.top();
                pq.pop();
            }
            cout<<"#"<<t<<" "<<answer<<endl;
        }
        
    } 

}