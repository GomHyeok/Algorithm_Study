#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int n, m, k;
long long numbers[1000001];
vector<long long> segmentTree;

long long init(long long start, long long end, long long node);
void updateTree(long long start, long long end, long long node, long long pos, long long value);
long long sum(long long start, long long end, long long node, long long left, long long right);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;

    for(int i=0; i<n; i++) {
        cin>>numbers[i];
    }

    int Depth = ceil(log2(n));
    int treeSize = 1 <<(Depth + 1);
    segmentTree.resize(treeSize);

    init(0, n-1, 1);

    for(int i=0; i<m+k; i++) {
        long long order, left, right;
        cin>>order>>left>>right;
        if(order == 1) {
            updateTree(0, n-1, 1, left-1, right-numbers[left-1]);
        } else {
             cout<<sum(0, n-1, 1, left-1, right-1)<<"\n";
        }
    }

}

long long init(long long start, long long end, long long node) {
    if(start == end) {
        return segmentTree[node] = numbers[start];
    }
    long long mid = (start+end)/2;
    return segmentTree[node] = init(start, mid, node * 2) + init(mid+1, end, node * 2 + 1);
}

void updateTree(long long start, long long end, long long node, long long pos, long long value) {
    if(pos < start || pos > end) return;
    segmentTree[node] += value;
    long long mid = (start + end) / 2;
    if(start == end) return;
    updateTree(start, mid, node*2, pos, value);
    updateTree(mid+1, end, node*2+1, pos, value);
}

long long sum(long long start, long long end, long long node, long long left, long long right) {
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) {
        return segmentTree[node];
    }
    long long mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid+1, end, node * 2 + 1, left, right);
}