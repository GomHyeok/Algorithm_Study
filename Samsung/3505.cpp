#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int testCase;
int n;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>testCase;

    for(int t = 1; t<= testCase; t++) {
        vector<int> jumpBoard;
        vector<int> result;
        int pos = 0;
        int answer = 0;
        cin>>n;

        pos = n-1;

        result.resize(n);

        for(int i=0; i<n; i++) {
            int j;
            cin>>j;
            jumpBoard.push_back(j);
        }

        sort(jumpBoard.begin(), jumpBoard.end());

        for(int i=0; i<n; i++) {
            if(i % 2 == 1) {
                result[pos] = jumpBoard[i];
                pos--;
            } else {
                result[(n-1) - pos] = jumpBoard[i];
            }
        }

        for(int i=0; i<n; i++) {
            if(i == n-1) {
                answer = max(answer, abs(result[i] - result[0]));
            } else answer = max(answer, abs(result[i] - result[i+1]));
        }

        cout<<"#"<<t<<" "<<answer<<endl;
        
    }
}