#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

int testCase;
int n, m; //n = 로봇 개수, m = 건물 개수

int main() {

    cin>>testCase;

    for(int i=1; i<=testCase; i++) {
        vector<long long> possibleBuilding[200];
        vector<long long> limit; // 최소 개수
        vector<long long> under;  //최대 개수
        vector<long long> answer;
        cin>>n>>m;

        answer.resize(m, -1);

        for(int i=0; i<n; i++) {
            int g;
            cin>>g;
            for(int j=0; j<g; j++) {
                int build;
                cin>>build;
                possibleBuilding[i].push_back(build);
            }
        }

        for(int i=0; i<m; i++) {
            int l, u;
            cin>>l>>u;
            limit.push_back(l);
            under.push_back(u);
        }
    }

}
