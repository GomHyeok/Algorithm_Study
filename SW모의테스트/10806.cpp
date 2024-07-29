#include<iostream>
#include <vector>
#include <queue>

using namespace std;

vector<long long> a;

long long k;
long long answer;
int n;

void init() {
    cin>>n;
    a.clear();
    answer = 0;
    for(int i=0; i<n; i++) {
        long long num;
        cin>>num;
        a.push_back(num);
    }
    cin>>k;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, k});

        while(!pq.empty()) {
            int cnt = pq.top().first;
            int value = pq.top().second;

            pq.pop();

            if(value == 0) {
                answer = cnt;
                break;
            }

            pq.push({cnt + value, 0});

            for(int i=0; i<n; i++) {
                pq.push({cnt + value%a[i], value/a[i]});
            }
        }

        cout<<"#"<<test_case<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

