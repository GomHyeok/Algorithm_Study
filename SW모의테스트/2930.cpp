#include<iostream>
#include <queue>

using namespace std;

int n;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout<<"#" << test_case;
        priority_queue<long long, vector<long long>> pq;
        cin>>n;
        
        for(int i=0; i<n; i++) {
            int todo;
            cin>>todo;
            if(todo == 1) {
                long long value;
                cin>>value;
                pq.push(value);
            } else {
                long long value;
                if(pq.empty()) {
                    value = -1;
                } else {
                    value = pq.top();
                    pq.pop();
                }
                cout<<" "<<value;
            }
        }
        cout<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}