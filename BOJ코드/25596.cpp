#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
int s;
queue<int> boxs[2002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;

    for(int i=1; i<=n; i++) {
        int c;
        cin>>c;

        for(int j=0; j<c; j++) {
            int a;
            cin>>a;
            boxs[i].push(a);
        }
    }

    for(int i=1; i<=n; i++) {
        if(s > k) break;

        while(1) {
            if(boxs[i].size() <= m) break;

            if(s+1 > k) {
                cout<<0<<"\n";
                return 0;
            }
            s+=1;

            for(int j=0; j<m; j++) {
                boxs[n+s].push(boxs[i].front());
                boxs[i].pop();
            }

            boxs[i].push(n+s);
        }
    }

    cout<<1<<"\n"<<s<<"\n";

    for(int i=1; i<=n+s; i++) {
        cout<<boxs[i].size();

        while (!boxs[i].empty())
        {
            cout<<" "<<boxs[i].front();
            boxs[i].pop();
        }

        cout<<"\n";
        
    }
}