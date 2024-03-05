#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n;
int answer = 50;
int damage[3];
int hp[61][61][61];

void attack(int a, int b, int c, int count);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>damage[i];
    }

    attack(damage[0], damage[1], damage[2], 0);

    cout<<answer<<endl;
}

void attack(int a, int b, int c, int count) {
    if(a <= 0 && b <=0 && c<= 0) {
        if(answer > count)  {
            answer = count;
        }
        return;
    }

    if(a < 0) a = 0;
    if(b < 0) b = 0;
    if(c < 0) c = 0;

    if(hp[a][b][c] <= count && hp[a][b][c] != 0) return;

    attack(a - 9, b -3, c -1, count + 1);
    attack(a - 9, b -1, c -3, count + 1);
    attack(a - 3, b -9, c -1, count + 1);
    attack(a - 1, b -9, c -3, count + 1);
    attack(a - 3, b -1, c - 9, count + 1);
    attack(a - 1, b - 3, c - 9, count + 1);
}