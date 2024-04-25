#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int x1, x2, x3;
int y4, y2, y3;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int s;

    cin>>x1>>y4;
    cin>>x2>>y2;
    cin>>x3>>y3;

    s = x1*y2 + x2*y3 + x3*y4 - x2*y4 - x3*y2 - x1*y3;

    if(s<0) cout<<-1<<endl;
    else if(s >0) cout<<1<<endl;
    else cout<<0<<endl;
}