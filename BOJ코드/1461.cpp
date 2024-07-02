#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int n, m;
int pos;
int minusBook;
int answer;
vector<int> books;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        if(a < 0) {
            minusBook++;
        }
        books.push_back(a);
    }

    sort(books.begin(), books.end());

    for(int i=n-1; i>=minusBook; i-=m) {
        answer += (books[i] * 2); // 양수인 책들
    }

    for(int i=0; i<minusBook; i+= m) {
        answer += abs(books[i] * 2); // 음수인 책들
    }

    answer -= max(abs(books[0]), abs(books[n-1])); //어느 방향으로 먼저 갈것인가

    cout<<answer<<endl;

    return 0;
}