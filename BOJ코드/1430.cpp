#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int n;
int r;
int d;
int x, y;
vector<pair<int, pair<int, int>>> tower;
bool possible[50];

double makeDir(int a, int b) {
    return sqrt(pow(abs(a-x), 2) + pow(abs(b-y), 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>r>>d>>x>>y;

    for(int i=0; i<n; i++) {
        int a, b;
        cin>>a>>b;
        if(makeDir(a, b) <= r) possible[i] = true;
        tower.push_back({d, {a, b}});
    }

    

}