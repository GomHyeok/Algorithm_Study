#include <vector>
#include <iostream>
#include <list>

using namespace std;

int n, m, l;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        list<long long> number;
       
        cin>>n>>m>>l;

        for(long long i=0; i<n; i++) {
            long long value;
            cin>>value;
            
            number.push_back(value);
        }

        for(int i=0; i<m; i++) {
            char c;
            long long a, b;

            cin>>c>>a;

            if(c == 'I') {
                cin>>b;
                list<long long>::iterator cur = number.begin();

                for(int i=0; i<a; i++) {
                    cur++;
                }

                number.insert(cur, b);
            }else if(c == 'D') {
                list<long long>::iterator cur = number.begin();
                
                for(int i=0; i<a; i++) {
                    cur++;
                }

                number.erase(cur);

            } else {
                cin>>b;
                list<long long>::iterator cur = number.begin();
                
                for(int i=0; i<a; i++) {
                    cur++;
                }

                *cur = b;
            }
        }
        if(number.size() <= l || l < 0) {
                cout<<"#" << test_case<<" "<<-1<<endl;;
            } else {
                list<long long>::iterator cur = number.begin();
                for(int i=0; i<l; i++) {
                    cur++;
                }
                cout<<"#" << test_case<<" "<<*cur<<endl;
            }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
