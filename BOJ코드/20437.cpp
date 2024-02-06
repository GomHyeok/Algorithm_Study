#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define MAX_VAL 9999999

using namespace std;

int k;
int test;
int min_answer = MAX_VAL;
int max_answer;
string w;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>test;

    while(test > 0) {
        test--;
        cin>>w;
        cin>>k;

        vector<int> count(26, 0);

        min_answer = MAX_VAL;
        max_answer = -1;

        for(int i=0; i<w.size(); i++) {
            count[w[i] - 'a']++;
        }

        for (int i = 0; i < w.size(); ++i) {
            if (count[w[i] - 'a'] < k)
                continue;

            int cnt = 0;
            for (int j = i; j < w.size(); ++j) { 
                if (w[i] == w[j]) 
                    ++cnt;
                
                if (cnt == k) {
                    min_answer = min(min_answer, j - i + 1);
                    max_answer = max(max_answer, j - i + 1);
                    break;
                }
            }
        }

        if(min_answer == MAX_VAL || max_answer == -1) {
            cout<<-1<<endl;
        }
        else {
            cout<<min_answer<<" "<<max_answer<<endl;
        }
    }
}