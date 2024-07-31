#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

string st;
bool isReverse;
unordered_map<string, int> subStrings;

// void printValues() {
// 	if(isReverse) {
// 		cout<<"isReverse"<<endl;
// 		for(int i = st.size()-1; i>=0; i--) {
// 			cout<<st[i];
// 		}
// 		cout<<endl;
// 		// for(auto it : subStrings) {
// 		// 	cout<<it.first<<" : "<<it.second<<endl;
// 		// }
// 	} else {
// 		cout<<"notReverse"<<endl;
// 		cout<<st<<endl;
// 		// for(auto it : subStrings) {
// 		// 	cout<<it.first<<" : "<<it.second<<endl;
// 		// }
// 	}
// }

void appendString() {
	string tmp = "";

	if(isReverse){
		for(int i=0; i<min((int)st.size(), 4); i++) {
			tmp += st[i];
			subStrings[tmp]++;
			//cout<<tmp<<" : "<<subStrings[tmp]<<endl;
		}
	} else {
		for(int i = st.size() - 1; i >= max((int)st.size()-4, 0); i--) {
			tmp = st[i] + tmp;
			subStrings[tmp]++;
			//cout<<tmp<<" : "<<subStrings[tmp]<<endl;
		}
	}
}

void deleteString() {
	string tmp = "";

	if(isReverse){
		for(int i=0; i<min((int)st.size(), 4); i++) {
			tmp += st[i];
			subStrings[tmp]--;
			//cout<<tmp<<" : "<<subStrings[tmp]<<endl;
		}
	} else {
		for(int i = st.size() - 1; i >= max((int)st.size()-4, 0); i--) {
			tmp = st[i] + tmp;
			subStrings[tmp]--;
			//cout<<tmp<<" : "<<subStrings[tmp]<<endl;
		}
	}
}

void init(char mStr[])
{
	st = mStr;
	isReverse = false;
	subStrings.clear();

	for(int i=1; i<=4; i++) {
		for(int j=0; j<=st.size() - i; j++) {
			subStrings[st.substr(j, i)]++;
		}
	}

	//printValues();
}

void appendWord(char mWord[])
{
	string tmp = mWord;
	for(int i=0;i <tmp.size(); i++) {
		if(isReverse) {
			st = tmp[i] + st;
		}
		else {
			st = st + tmp[i];
		}
		appendString();
	}

	//printValues();
}

void cut(int k)
{
	for(int i=0; i<k; i++) {
		deleteString();
		if(isReverse) {
			st.erase(0, 1);
		} else {
			st.erase(st.end()-1);
		}
	}

	//printValues();
}

void reverse()
{
	isReverse = !isReverse;
}

int countOccurrence(char mWord[])
{
	string tmp = mWord;
	if(isReverse) reverse(tmp.begin(), tmp.end());
	//cout<<subStrings[tmp]<<endl;
	return subStrings[tmp];
}