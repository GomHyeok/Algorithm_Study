#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n;
vector<string> words;
map<string, string> trans = { {"a", "a"},{"b","b"},{"k","c"},{"d","d"},{"e","e"},{"g","f"},
	{"h","g"},{"i","h"},{"l","i"},{"m","j"},{"n","k"},{"ng","l"},{"o","m"},{"p","n"},
	{"r","o"},{"s","p"},{"t","q"},{"u","r"},{"w","s"},{"y","t"} };

map<string, string> minToAlpa;

int main() {
    cin>>n;

    for(int i=0; i<n; i++) {
        string st;
        cin>>st;
        string translate = "";

        for(int j=0; j<st.size(); j++) {
            if(st[j] == 'n') {
                if(j<st.size()-1 && st[j+1] == 'g') {
                    translate += trans["ng"];
                    j++;
                } else {
                    translate += trans["n"];
                }
            } else {
                string key = string(1, st[j]);
                translate += trans[key];
            }
        }
        words.push_back(translate);
        minToAlpa[translate] = st;
    }

    sort(words.begin(), words.end());

    for(int i=0; i<words.size(); i++) {
        cout<<minToAlpa[words[i]]<<endl;
    }
}