#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

long long n;
long long answer;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int T;
    
    scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%lld", &n);
        long long target = 2 * n;
        long long tmp = static_cast<long long>(sqrt(target));
        answer = -1;

        if (tmp * (tmp + 1) == target) {
            answer = tmp;
        } else if ((tmp - 1) * tmp == target) {
            answer = tmp - 1;
        }

        printf("#%d %lld\n", test_case, answer);
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}
