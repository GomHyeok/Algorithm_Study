#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#define INF 987654321987

using namespace std;

int test_case;
int k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>test_case;

    while(test_case) {
        cin>>k;
        priority_queue<long long, vector<long long>> large;
        priority_queue<long long, vector<long long>, greater<long long>> small;
        map<int, int> check;
        long long lvalue = INF;
        long long svalue = INF;

        for(int i=0; i<k; i++) {
            long long num;
            char ch;
            cin>>ch>>num;

            if(ch == 'I') {
                large.push(num);
                small.push(num);
                if(check[num] == 0) check[num] = 1;
                else check[num]++;
            } else {
                if(num == -1) {
                    while(!small.empty()) {
                        int n = small.top();
                        small.pop();
                        if(check[n] > 0) {
                            check[n]--;
                            break;
                        }
                    }
                } else {
                    while(!large.empty()) {
                        int n = large.top();
                        large.pop();
                        if(check[n] > 0) {
                            check[n]--;
                            break;
                        }
                    }
                }
            }
        }

        while(!large.empty()) {
            int n = large.top();
            large.pop();
            if(check[n] > 0) {
                lvalue = n;
                break;
            }
        }
        while(!small.empty()) {
            int n = small.top();
            small.pop();
            if(check[n] > 0) {
                svalue = n;
                break;
            }
        }

        if(lvalue == INF|| svalue == INF) {
            cout<<"EMPTY"<<"\n";
        } else {
            cout<<lvalue<<" "<<svalue<<"\n";
        }

        test_case--;
    }
}