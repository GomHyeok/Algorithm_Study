#include <iostream>
#include <vector>

using namespace std;

int days[13] = {0, 31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int d, m, y;

    while(1) {
        int answer = 0;

        cin>>d>>m>>y;

        if(d==0 && m == 0 && y ==  0) break;

        if(y % 4 == 0) {
            if(y % 100 != 0 || y % 400 == 0) days[2] = 29;
        }

        for(int i=1; i<m; i++) answer += days[i];
        answer += d;

        days[2] = 28;

        cout<<answer<<endl;
    }
}