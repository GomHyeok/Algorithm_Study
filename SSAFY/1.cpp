#include <iostream>

using namespace std;

int a[501];
int answer;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	ios::sync_with_stdio(false);

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
        int n, d, x;

        answer = 0;

        cin>>n>>d>>x;
        for(int i=1; i<=n; i++) {
            cin>>a[i];
        }

        if(d <= x) {
            answer = a[d] * n + (x-d);
        } else {
            answer = a[d] * n + (n-d) + x;
        }

		cout << "#" << test_case <<" "<<answer<<endl;
	}

	return 0;
}

/*
3
4 2 3
3 2 4 5
4 1 3
0 1 1 1
4 2 2
1 1 1 1
*/