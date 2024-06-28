#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>testcase;

    while(testcase) {
        string st;
        int pos = 0;
        bool flag = false;
        cin>>st;
        
        while(pos < st.size()) {
            if(st[pos] == '1') {
                if(pos+1 < st.size() && st[pos+1] == '0') {
                    pos++;
                    int count = 0;
                    while(pos < st.size() && st[pos] == '0') {
                        pos++;
                        count++;
                    }
                    if(count < 2) {
                        flag = true;
                        break;
                    }

                    if(pos < st.size() && st[pos] != '1') {
                        flag = true;
                        break;
                    } else if(pos >= st.size()) {
                        flag = true;
                        break;
                    }
                    while(pos < st.size() && st[pos] == '1') {
                        pos++;
                    }
                } else {
                    flag = true;
                    break;
                }
            }
            else if(st[pos] == '0') {
                if(pos-1 >= 0 && st[pos-1] == '1') {
                    if(pos-2 >= 0 && st[pos-2] == '1') {
                        pos--;
                        continue;
                    } else if(pos-2 >= 0 && st[pos-2] == '0') {
                        if(pos+1 < st.size() && st[pos+1] != '1') {
                            flag = true;
                            break;
                        } else {
                            pos+=2;
                            continue;
                        }
                    } else {
                        flag = true;
                        break;
                    }
                }
                else if(pos == 0){
                    if(pos+1<st.size() && st[pos+1] != '1') {
                        flag = true;
                        break;
                    } else {
                        pos += 2;
                        continue;
                    }
                }
                else {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) {
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
        testcase--;
    }

}