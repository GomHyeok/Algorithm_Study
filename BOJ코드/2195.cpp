#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

string s, p;
int i;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>p;
    int useCopy = 0;

    while(i<p.size()) {
        int maxl = 0;
        for(int j=0; j<s.size(); j++){
            int use = 0;
            while(s[j+use] == p[i+use]) use++;
            maxl = max(maxl, use);
        }
        i+=maxl;
        useCopy++;
    }

    cout<<useCopy<<"\n";
}