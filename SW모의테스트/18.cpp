#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 100000;
int min_tree[4 * MAXN];
int max_tree[4 * MAXN];

void build(vector<int>& data, int node, int start, int end) {
    if (start == end) {
        min_tree[node] = data[start];
        max_tree[node] = data[start];
    } else {
        int mid = (start + end) / 2;
        build(data, 2 * node + 1, start, mid);
        build(data, 2 * node + 2, mid + 1, end);
        min_tree[node] = min(min_tree[2 * node + 1], min_tree[2 * node + 2]);
        max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
    }
}

void update(int node, int start, int end, int idx, int value) {
    if (start == end) {
        min_tree[node] = value;
        max_tree[node] = value;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, value);
        } else {
            update(2 * node + 2, mid + 1, end, idx, value);
        }
        min_tree[node] = min(min_tree[2 * node + 1], min_tree[2 * node + 2]);
        max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
    }
}

pair<int, int> query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
        return {INT_MAX, INT_MIN};
    }
    if (L <= start && end <= R) {
        return {min_tree[node], max_tree[node]};
    }
    int mid = (start + end) / 2;
    auto left = query(2 * node + 1, start, mid, L, R);
    auto right = query(2 * node + 2, mid + 1, end, L, R);
    return {min(left.first, right.first), max(left.second, right.second)};
}

int main() {
    int T;
    cin >> T;
    
    for(int t = 1; t<=T; t++) {
        int n, q;
        cin >> n >> q;
        vector<int> data(n);
        
        for (int i = 0; i < n; i++) {
            cin >> data[i];
        }
        
        build(data, 0, 0, n - 1);
        
        vector<int> results;
        
        for (int i = 0; i < q; i++) {
            int type;
            cin >> type;
            if (type == 0) {
                int idx, value;
                cin >> idx >> value;
                update(0, 0, n - 1, idx, value);
            } else if (type == 1) {
                int l, r;
                cin >> l >> r;
                auto result = query(0, 0, n - 1, l, r - 1);
                results.push_back(result.second - result.first);
            }
        }
        
        cout << "#"<<t<<" ";
        
        for (int i = 0; i < results.size(); i++) {
            cout << results[i];
            if (i != results.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
