#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int n;
long long answer;
vector<pair<int, int>> path;

long long hanoie(int n, int start, int finish, int bypass);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    answer = hanoie(n, 1, 3, 2);
    cout<<answer<<"\n";

    for(long long i=0; i<answer; i++) {
        cout<<path[i].first<<" "<<path[i].second<<"\n";
    }
}

long long hanoie(int n, int start, int finish, int bypass) {
    long long result = 0;
    if(n==1) {
        path.push_back({start, finish});
        return 1;
    }

    result += hanoie(n-1, start, bypass, finish);
    result ++;
    path.push_back({start, finish});
    result += hanoie(n-1, bypass, finish, start);

    return result;
}

