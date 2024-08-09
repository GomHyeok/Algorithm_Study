#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int testCase;
int n;
string x;

struct Info {
    long long sum;
    int idx;
    int plusCnt;

    Info(long long sum, long long idx, long long plusCnt): sum(sum), idx(idx), plusCnt(plusCnt) {
    }
};

struct compare {
    bool operator()(const Info& a, const Info& b) const {
        if(a.sum == b.sum) {
            return a.idx > b.idx;
        }
        return a.sum > b.sum;
    }
};

int  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>testCase;

    for(int t=1; t<=testCase; t++) {
        vector<int> arr;
        priority_queue<Info, vector<Info>, compare> pq;
        queue<pair<pair<long long, long long>, pair<long long, long long>>> q;
        vector<long long> sumValue;
        vector<long long> plusValue;
        long long answer_s = 0;
        long long answer_p = 0;
        long long index = 0;
        cin>>n;
        cin>>x;

        for(int i=0; i<n; i++) {
            int a;
            cin>>a;
            arr.push_back(a);
        }

        q.push({{0, 0}, {x[0]-'0', 0}});

        while(!q.empty()) {
            long long nowSum = q.front().first.first;
            long long plusCnt = q.front().first.second;
            long long nowValue = q.front().second.first;
            long long idx = q.front().second.second;
            q.pop();

            if(idx == x.size()-1) {
                pq.push(Info(nowSum + nowValue, index, plusCnt));
                index++;
                continue;
            }

            q.push({{nowSum + nowValue, plusCnt+1}, {x[idx+1] - '0', idx + 1}});
            q.push({{nowSum, plusCnt}, {nowValue*10 + x[idx+1]-'0', idx+1}});
        }

        while(!pq.empty()) {
            sumValue.push_back(pq.top().sum);
            plusValue.push_back(pq.top().plusCnt);

            pq.pop();
        }

        //cout<<sumValue.size()<<" "<<plusValue.size()<<endl;

        for(int i=0; i<n; i++) {
            answer_s += sumValue[arr[i]-1];
            answer_p += plusValue[arr[i]-1];
        }

        cout<<answer_s<<" "<<answer_p<<endl;
    }

}