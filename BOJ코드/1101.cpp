#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int boxs[51][51];
bool colors[51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int answer = 500000;

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>boxs[i][j];
        }
    }

    for(int joker = 0; joker < n; joker++) {
        memset(colors, false, m);

        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(joker == i) continue;
            int color = 0;
            int deff = 0;

            for(int j=0; j<m; j++) {
                if(boxs[i][j] != 0) {
                    color = j;
                    deff++;
                }
            }

            if(deff == 1) {
                if(colors[color]) { cnt++; }
                else colors[color] = true;
            } else if(deff == 0) {
                continue;
            } else {
                cnt++;
            }      
        }

        answer = min(answer, cnt);
    }

    cout<<answer<<endl;
}