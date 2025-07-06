#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long x, y, z;

int main() {
    cin>>x>>y;
    z = y*100/x;

    if(z >= 99) {
        cout<<-1<<endl;
        return 0;
    }

    long long right = 1000000000;
    long long left = 0;

    while(left <= right) {
        long long mid = (left + right) / 2;

        int percent = (100 * (y + mid)) / (x + mid);
        if(percent > z) right = mid-1;
        else left = mid + 1;
    }

    cout<<left<<endl;

}