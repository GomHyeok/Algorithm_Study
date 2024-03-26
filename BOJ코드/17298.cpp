#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n;
vector<int> numbers;
vector<int> answers;
int pos[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        numbers.push_back(a);
    }

    pos[n] = n;
    pos[n-1] = n;

    for(int i=n-2; i>=0; i--) {
        int compare = i+1;
        if(numbers[i] < numbers[compare]) {
            pos[i] = compare;
            continue;
        }
        
        while(compare < n) {
            int value = pos[compare];
            if(numbers[i] < numbers[value]) {
                pos[i] = value;
                break;
            }
            compare = value;
        }
        if(pos[i] == 0 ) pos[i] = n;
    }
    for(int i=0; i<n; i++) {
        if(pos[i] == n) {
            cout<<-1<<" ";
        } else {
            cout<<numbers[pos[i]]<<" ";
        }
    }
    cout<<"\n";
}