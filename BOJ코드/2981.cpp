#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n;
int numbers[101];
vector<int> answers;

int gcd(int a, int b) {
    if(b==0) return a;

    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int maxValue;

    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>numbers[i];
    }

    sort(numbers, numbers+n);

    maxValue = numbers[1] - numbers[0];
    for(int i=2; i<n; i++) {
        maxValue = gcd(maxValue, numbers[i] - numbers[i-1]);
    }

    for(int i=1; i*i<=maxValue; i++) {
        if(maxValue % i == 0) {
            if(i!=1) answers.push_back(i);
            if(i != maxValue / i && maxValue/i != 1) answers.push_back(maxValue/i);
        }
    }

    sort(answers.begin(), answers.end());

    for(int i=0; i<answers.size(); i++) {
        cout<<answers[i]<<" ";
    }
}