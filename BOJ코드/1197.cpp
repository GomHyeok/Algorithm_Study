#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;
int v, e;
int parent[10001];
long long answer;
vector<pair<int, pair<int, int>>> path;

bool unions(int a, int b);
int union_find(int a);
bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int count = 0;
    int pos = 0;

    cin>>v>>e;

    for(int i=1; i<=v; i++) parent[i] = i;
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        path.push_back({c, {a, b}});
    }
    sort(path.begin(), path.end());

    while(count < v-1) {
        int a = path[pos].second.first;
        int b = path[pos].second.second;
        int value = path[pos].first;

        if(!unions(a, b)) {
            answer += value;
            count++;
        }
        pos++;
    }

    cout<<answer<<endl;

}

bool unions(int a, int b) {
    int pa = union_find(a);
    int pb = union_find(b);
    if(pa == pb) return true;
    if(pa > pb) {
        parent[pa] = pb; 
    } else {
        parent[pb] = pa;
    }
    return false;
}

int union_find(int a) {
    if(a == parent[a]) return parent[a];
    return union_find(parent[a]);
}