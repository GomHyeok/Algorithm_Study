#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;
long long build[51];
long long see[51];
long long answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>build[i];
    }

    for(int i=0; i<n; i++) {
        double max_val = -99999999999.0;
        
        for(int j=i+1; j<n; j++) {
            long long x = j-i;
            long long y = build[j] - build[i];
            double value = (y * 1.0) / x;

            if(value <= max_val) continue;

            see[i]++;
            see[j]++;

            max_val = value;
        }
    }

    for(int i=0; i<n; i++) {
        if(see[i] >= answer) answer = see[i];
    }

    cout<<answer<<endl;
    
}