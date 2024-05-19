#include<iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n, k,c;
int chef[12];
long long answer = 9876543210;

void check() {
    long long left = 1, right = 1000000000000;
	while(left <= right){
		long long mid = (left+right)/2;
		long long cnt = 0;
		for(int i = 0; i < n; i++){
			cnt += (mid/chef[i]);
		}
		if(cnt >= k){
			right = mid - 1;
			answer = min(answer, mid);
		}
		else {
			left = mid + 1;
		}
	}
}

void dfs(int cnt, int idx) {
    if(!cnt) {
        check();
        return;
    }

    for(int i=idx; i<n; i++) {
        if(chef[i] > 1) {
            chef[i]--;
            dfs(cnt-1, i);
            chef[i]++;
        } else {
            dfs(cnt-1, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>c;

    for(int i=0; i<n; i++) {
        cin>>chef[i];
    }

    dfs(c, 0);

    cout<<answer<<endl;
}

