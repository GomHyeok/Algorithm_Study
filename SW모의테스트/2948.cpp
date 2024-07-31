#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include <string>

using namespace std;

int n, m;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int answer = 0;
        unordered_set<string> check;

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            char ch[51];
            scanf("%s", ch);
            check.insert(string(ch));
        }

        for (int i = 0; i < m; i++) {
            char ch[51];
            scanf("%s", ch);
            if (check.find(string(ch)) != check.end()) {
                answer++;
            }
        }

        printf("#%d %d\n", test_case, answer);
    }
    return 0;
}
