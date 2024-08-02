#include<iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string st;
        string tmp = "";
        int k;
        vector<string> subString;
        cin>>k;
        cin>>st;

        for(int i=st.size()-1; i>=0; i--) {
            tmp  = st[i] + tmp;
            subString.push_back(tmp);
        }

        sort(subString.begin(), subString.end());

        // for(int i=0; i<subString.size(); i++) {
        //     cout<<subString[i]<<endl;
        // }

        cout<<"#"<<test_case<<" "<<subString[k-1]<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}