#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n;
long long answer;
int number[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<int, int> check;
    int start = 0;
    int end = 1;

    cin>>n;
    
    for(int i=0; i<n; i++) {
        cin>>number[i];
    }

    check[number[0]] = 1;

    while(true) {
        while(end < n && check[number[end]] == 0) {
            check[number[end]]++;
            end++;
        }
        if(start >= n || end > n) break;

        answer += end - start;
        check[number[start]]--;
        start++;
    }

    cout<<answer<<endl;
}