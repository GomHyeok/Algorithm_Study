#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int parent[1000001];
vector<string> answer;

void union_union(int a, int b);
int union_find(int a);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }

    for(int i=0; i<m; i++) {
        int operate;
        int unionA;
        int unionB;

        cin>>operate>>unionA>>unionB;

        if(operate == 0) {
            union_union(unionA, unionB);
        } else {
            int parentA = union_find(parent[unionA]);
            int parentB = union_find(parent[unionB]);
            if(parentA == parentB) {
                cout<<"YES"<<'\n';
            } else {
                cout<<"NO"<<'\n';
            }
        }
    }
    
}

void union_union(int a, int b) {
    int aParent = union_find(a);
    int bParent = union_find(b);
    if(aParent > bParent) parent[aParent] = bParent;
    else parent[bParent] = aParent;
}

int union_find(int a) {
    if(a == parent[a]) {
        return a;
    }
    return parent[a] = union_find(parent[a]);
}