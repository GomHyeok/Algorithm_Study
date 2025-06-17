#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//(100+1+ | 01)+
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testcase;

    cin>>testcase;

    for(int t=1; t<=testcase; t++) {
        string st;
        string answer = "YES";
        int idx = 0;

        cin>>st;

        while(idx < st.size()) {
            if(st[idx] == '0') {
                if(idx + 1 >= st.size() || st[idx+1] == '0') {
                    answer = "NO";
                    break;
                }
                idx += 2;
            } else {
                int nextOne = -1;
                for(int i=idx+1; i < st.size(); i++) {
                    if(st[i] == '1') {
                        nextOne = i;
                        break;
                    }
                }

                if(nextOne - idx < 3 || nextOne < 0) {
                    answer = "NO";
                    break;
                }

                int nextZero = -1;
                for(int i=nextOne + 1; i<st.size(); i++) {
                    if(st[i] == '0') {
                        nextZero = i;
                        break;
                    }
                }
                //0뒤에 아무것도 안오는 경우 없음
                if(nextZero == st.size() -1) {
                    answer = "NO";
                    break;
                }
                //0이 아에 없는 경우
                if(nextZero == -1) break;
                idx = nextZero;

                //100이 반복인 경우
                if(st[idx+1] == '0' && idx - nextOne > 1) idx--;
            }
        }

        cout<<answer<<"\n";
    }
}