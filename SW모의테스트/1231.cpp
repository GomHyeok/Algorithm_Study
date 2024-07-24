#include<iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int n;

char node[101];
int parent[101];
int child[2][101];
string answer = "";

void dfs(int now) {
    //leaf
    if(child[0][now] == 0) {
        answer+=node[now];
        return;
    }

    dfs(child[0][now]);
    answer += node[now];

    if(child[1][now] != 0) {
        dfs(child[1][now]);
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>n;

        memset(parent, 0, 101);
        memset(child[0], 0, 101);
        memset(child[1], 0, 101);
        answer = "";


        int perfect, leaf, other;
        if(n%2 == 0) {
            leaf = n/2;
        } else {
            leaf = (n+1)/2;
        }

        perfect = (n-1)/2;
        other = n-leaf-perfect;

        for(int j = 0; j<perfect; j++) {
            int now, child1, child2;
            char ch;
            cin>>now>>ch>>child1>>child2;
            node[now] = ch;
            child[0][now] = child1;
            child[1][now] = child2;
            parent[child1] = now;
            parent[child2] = now;
        }

        for(int j=0; j<other; j++) {
            int now, child1;
            char ch;
            cin>>now>>ch>>child1;
            node[now] = ch;
            child[0][now] = child1;
            parent[child1] = now;
        }

        for(int j=0; j<leaf; j++) {
            int now;
            char ch;
            cin>>now>>ch;
            node[now] = ch;
        }
        

        dfs(1);
        cout<<"#"<<test_case<<" "<<answer<<endl;
	}  
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

