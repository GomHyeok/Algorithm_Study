#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int answer;
int parent[201];
vector<int> citys;

int find(int x);
void union_find(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int past;

    cin>>n;
    cin>>m;

    for(int i=1; i<=n; i++) parent[i] = i;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int x;
            cin>>x;
            if(x == 1) union_find(i, j);
        }
    }

    for(int i=0; i<m; i++) {
        int num;
        cin>>num;
        citys.push_back(num);
    }

    past = find(citys[0]);

    for(int i=1; i<m; i++) {
        int now = find(citys[i]);
        if(past != now) {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;

}

int find(int x) {
    if(parent[x] == x) return x;

    return find(parent[x]);
}

void union_find(int x, int y) {
    int parentX = find(x);
    int parentY = find(y);

    if(parentX > parentY) parent[parentX] = parentY;
    else parent[parentY] = parentX;
}