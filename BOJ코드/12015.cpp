#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n;
int pos;
vector<int> arr;
vector<int> ans;

int binary(int num);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    ans.push_back(arr[0]);

    for(int i=1; i<n; i++) {
        if(arr[i] > ans[pos]) {
            ans.push_back(arr[i]);
            pos++;
        }
        else {
            int indx = binary(arr[i]);
            ans[indx] = arr[i];
        }
    }

    cout<<ans.size()<<endl;
}

int binary(int num) {
    int left = 0;
    int right = ans.size()-1;
    int mid;

    while(left < right) {
        mid = (left + right) / 2;

        if(ans[mid] >= num) right = mid;
        else left = mid + 1;
    }

    return right;
}