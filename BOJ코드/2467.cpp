#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//산성 = 양수, 아칼리성 = 음수
int n;
int answer[2];
long long value;
vector<long long> liquid;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) {
        int l;
        cin>>l;
        liquid.push_back(l);
    }

    int left = 0;
    int right = n-1;
    answer[0] = 0;
    answer[1] = n-1;
    value = abs(liquid[0] + liquid[right]);

    while(left < right) {
        long long sum = liquid[left] + liquid[right];

        if(abs(sum) <= value) {
            value = abs(sum);
            answer[0] = left;
            answer[1] =right;
        }

        if(sum < 0 ) left++;
        else right--;
    }

    cout<<liquid[answer[0]]<<" "<<liquid[answer[1]]<<endl;

}