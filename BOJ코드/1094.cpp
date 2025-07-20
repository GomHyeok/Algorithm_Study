#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dist = 64;
    int answer = 0;
    cin>>x;

    while(x > 0) {
        if(dist > x) dist /= 2;
        else {
            answer++;
            x -= dist;
        }
    }

    cout<<answer<<endl;
}