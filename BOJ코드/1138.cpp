#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    vector<int> answer(n, 0);

    for(int i=1; i<=n; i++) {
        int cnt;
        cin>>cnt;
        
        for(int j=0; j<n; j++) {
            if(cnt == 0 && answer[j] == 0) {
                answer[j] = i;
                break;
            }
            if(answer[j] == 0) cnt--;
        }
    }

    for(int i=0; i<n; i++) {
        cout<<answer[i]<<" ";
    }

}