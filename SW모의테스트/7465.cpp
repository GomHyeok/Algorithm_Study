#include<iostream>
#include <cstring>

using namespace std;

int n, m;
int parent[101];
bool check[201];

int findParent(int a) {
    if(parent[a] == a) {
        return a;
    }
    return findParent(parent[a]);
}

void unionParent(int a, int b) {
    if(parent[a] > parent[b]) {
        parent[a] = parent[b];
    } else {
        parent[b] = parent[a];
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

    cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer = 0;
        memset(check, 0, 200);
        cin>>n>>m;
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }

        for(int i=0; i<m; i++) {
            int a, b;
            int pa, pb;
            cin>>a>>b;
            
            pa = findParent(a);
            pb = findParent(b);

            if(pa != pb) {
                unionParent(pa, pb);
            }
        }

        for(int i=1; i<=n; i++) {
            int p = findParent(i);
            if(parent[i] != p) {
                parent[i] = p;
            }
        }
        
        for(int i=1; i<=n; i++) {
            if(!check[parent[i]]) {
                answer++;
                check[parent[i]] = true;
            }
        }

        cout<<"#"<<test_case<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}