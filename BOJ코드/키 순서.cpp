#include <iostream>
#include <vector>

#define MAX_INT 987654321

using namespace std;

int main() {
    int n , m;
    int counts[501][501];
    int answer = 0;

    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            counts[i][j] = MAX_INT;
        }
    }

    for(int i=0; i<m; i++) {
        int a, b;
        cin>>a>>b;
        counts[a][b] = 1;
    }

    for(int k = 1; k <= n; k++) {
        for(int i=1; i <= n; i++) {
            for(int j=1; j<=n; j++) {
                counts[i][j] = min(counts[i][j], counts[i][k] + counts[k][j]);
            }
        }
    }

    for(int i=1; i<= n; i++) {
        int cnt = 0;
        for(int j=1; j<=n; j++) {
            if(counts[i][j] != MAX_INT) cnt++;
            if(counts[j][i] != MAX_INT) cnt++;
        }
        if(cnt == n-1) answer++;
    }
    
    cout<<answer<<endl;
}