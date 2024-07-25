#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip> 

using namespace std;

int n;
double e;

struct Bridge {
    int s, e;
    double cost;
};

bool compare(Bridge a, Bridge b) {
    return a.cost < b.cost;
}

int find(vector<int>& parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

double kruskal(int cnt, vector<Bridge>& bridge) {
    sort(bridge.begin(), bridge.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    double totalCost = 0.0;
    for (Bridge& edge : bridge) {
        if (find(parent, edge.s) != find(parent, edge.e)) {
            unite(parent, rank, edge.s, edge.e);
            totalCost += edge.cost;
        }
    }
    return totalCost;
}

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> n;
        vector<pair<int, int>> lands;
        vector<int> x;
        vector<int> y;
        for (int i = 0; i < n; i++) {
            int a;
            cin>>a;
            x.push_back(a);
        }

        for (int i = 0; i < n; i++) {
            int a;
            cin>>a;
            y.push_back(a);
        }

        for (int i = 0; i < n; i++) {
            lands.push_back({x[i], y[i]});
        }

        cin >> e;

        vector<Bridge> bridge;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = pow(lands[i].first - lands[j].first, 2) + pow(lands[i].second - lands[j].second, 2);
                double cost = e * dist;
                bridge.push_back({i, j, cost});
            }
        }
        double cost = kruskal(n, bridge);


        cout << "#" << test_case << " " << fixed << setprecision(0) << cost << endl;
    }
    return 0; // 정상 종료 시 반드시 0을 리턴해야 합니다.
}
