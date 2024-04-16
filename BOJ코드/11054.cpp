#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int first[10001];
int last[10001];
int n;
int answer;
vector<int> numbers;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        int num;
        cin>>num;
        numbers.push_back(num);
    }

    first[0] = 1;

    for(int i=1; i<n; i++) {
        first[i] = 1;
        for(int j=0; j<=i; j++) {
            if(numbers[j] < numbers[i] && first[i] < first[j] + 1) {
                first[i] = first[j] +1;
            }
        }
    }

    last[n-1] = 1;

    for(int i=n-2; i>=0; i--) {
        last[i] = 1;
        for(int j=n-1; j>=i; j--) {
            if(numbers[j] < numbers[i] && last[i] < last[j] + 1) {
                last[i] = last[j] +1;
            }
        }
    }

    for(int i=0; i<n; i++) {
        answer = max(answer, first[i] + last[i]-1);
    }

    cout<<answer<<endl;

}