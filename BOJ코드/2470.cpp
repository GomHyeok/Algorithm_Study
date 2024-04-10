#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n;
long long answer[2];
long long sum = 10000000000;
vector<long long> liqud;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) {
        long long li;
        cin>>li;
        liqud.push_back(li);
    }

    sort(liqud.begin(), liqud.end());

    int left = 0;
    int right = n-1;

    while(left < right) {
        int value = liqud[left] + liqud[right];

        if(sum > abs(value)) {
            sum = abs(value);
            answer[0] = liqud[left];
            answer[1] = liqud[right];

            if(sum == 0) break;
        }

        if(value < 0) left++;
        else right--;
    }

    cout<<answer[0]<<" "<<answer[1]<<"\n";
}