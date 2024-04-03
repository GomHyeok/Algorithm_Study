#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

bool numbers[1000003];
long long answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long minVal, maxVal;
    
    cin>>minVal>>maxVal;

    for(long long i = 2; i * i<=maxVal; i++) {
        long long n = minVal / (i*i);
        if(minVal % (i*i)) n++;

        while(n*i*i <= maxVal) {
            numbers[n*i*i - minVal] = true;
            n++;
        }
    }

    for(int i=0; i<=maxVal - minVal; i++) {
        if(!numbers[i]) answer++;
    }

    cout<<answer<<"\n";
}