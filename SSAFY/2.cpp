#include <iostream>
#include <vector>

using namespace std;

long long answer;
int n;
int a[1000], b[1000];

long long d(int aStart, int bStart);

int main(int argc, char** argv)
{
	int test_case;
	int T;

	ios::sync_with_stdio(false);

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
        answer = 0;
        vector<vector<int>> cnt(2001, vector<int>());

        cin>>n;

        for(int i=0; i<n; i++) {
            cin>>a[i];
        }

        for(int i=0; i<n; i++) {
            cin>>b[i];
            cnt[b[i]].push_back(i);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<cnt[a[i]].size(); j++) {
                long long tmp = d(i, cnt[a[i]][j]);
                answer = max(answer, tmp);
            }
        }

		cout << "#" << test_case << " " << answer << endl;
	}

	return 0; 
}

long long d(int aStart, int bStart) {
    long long cnt = 0;

    if(aStart > bStart) {
        int aS = aStart;
        int bS = bStart;

        while(aS < n) {
            if(a[aS] == b[bS]) cnt++;
            aS++;
            bS++;
        }
    } else {
        int aS = aStart;
        int bS = bStart;

        while(bS < n) {
            if(a[aS] == b[bS]) cnt++;
            aS++;
            bS++;
        }
    }

    return cnt;
}



        // for(int i=0; i<n; i++) {
        //     cout<<a[i]<<" "<<b[i]<<endl;
        //     for(int j=0; j<cnt[a[i]].size(); j++) {
        //         cout<<cnt[a[i]][j]<<" ";
        //     }
        //     cout<<endl;
        // }