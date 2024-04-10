#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;
int del;
int root;
long long answer;
bool possible[51];
vector<int> path[51];

int dfs(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<int> q;

    cin>>n;

    for(int i=0; i<n; i++) {
        int parent;
        cin>>parent;
        if(parent == -1) {
            root = i;
        } else {
            path[parent].push_back(i);
        }
    }

    cin>>del;

    dfs(root);

    cout<<answer<<"\n";

}

int dfs(int node) {
    if(node == del) return -1;
    if (!path[node].size()) {
		answer++;
		return 0 ;
	}
	for (int i = 0; i < path[node].size(); i++) {
		int tmp = dfs(path[node][i]);
		if (tmp == -1 && path[node].size() == 1)
			answer++;
	}
	return 0;
}