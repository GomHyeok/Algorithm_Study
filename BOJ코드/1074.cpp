#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, r, c;
long long answer;
long long pos = 1;
long long block = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>r>>c;

    for(int i=0; i<n; i++) {
        pos *= 2;
    }

    block = (pos / 2) * (pos / 2);

    while(n > 0) {
        int position = 0;

        if(r >= (pos/2)){
            r -= (pos/2);
            if( c >= (pos/2)) {
                position = 3;
                c -= (pos/2);
            }
            else {
                position = 2;
            }
        } else {
            if( c >= (pos/2)) {
                position = 1;
                c -= (pos/2);
            }
            else {
                position = 0;
            }
        }

        answer += (position * block);
        pos /= 2;
        block/=4;
        n--;
    }

    cout<<answer<<endl;

}