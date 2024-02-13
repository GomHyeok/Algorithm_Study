#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int n;
int answer;
vector<int> number;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        number.push_back(a);
    }

    sort(number.begin(), number.end());

    if(n<=2) {
        cout<<0<<endl;
        return 0;
    }

    for(int i=0; i<n; i++) {
        vector<int> tmp = number;
        tmp.erase(tmp.begin() + i);

        int start = 0; 
        int end = n-2;

        while (start < end) {
            int sum = tmp[start] + tmp[end];

            if(sum == number[i]) {
                answer++;
                break;
            }

            if(sum < number[i]) start++;
            else end--;
        }
    }

    cout<<answer<<endl;
}