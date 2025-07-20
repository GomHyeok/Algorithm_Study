#include <iostream>
#include <vector>

using namespace std;

int testcase;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>testcase;

    for(int i=0; i<testcase; i++) {
        cin>>n>>m;
        int result = 1;
        int div = 1;

        for(int j=m; j>m-n; j--) {
            result *= j;
            result /= div;
            div++;
        }

        cout<<result<<endl;
    }
}