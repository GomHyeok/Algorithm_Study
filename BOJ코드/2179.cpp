#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n;
string words[20000];
pair<string, int> first_pair;
pair<string, int> second_pair;
int max_len;
vector<pair<string, int>> dic;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>words[i];
        dic.push_back({words[i], i});
    }

    sort(dic.begin(), dic.end());

    for(int i=0; i<n-1; i++) {
        string standard = dic[i].first;
        
        for(int j=i+1; j<n; j++) {
            string cmp = dic[j].first;
            int tmp = 0;
            int len = min(cmp.size(), standard.size());
            if(cmp[0] != standard[0]) break;
            for(int k=0; k<len; k++) {
                if(cmp[k] != standard[k]) break;
                tmp++;
            }

            if(tmp == max_len) {
                if(dic[i].second < dic[j].second) {
                    if(dic[i].second < first_pair.second) {
                        first_pair  = dic[i];
                        second_pair = dic[j];
                    }
                }
                else {
                    if(dic[j].second < first_pair.second) {
                        first_pair  = dic[j];
                        second_pair = dic[i];
                    }
                }
            }
            else if(tmp > max_len) {
                max_len = tmp;
                if(dic[i].second < dic[j].second) {
                    first_pair  = dic[i];
                    second_pair = dic[j];
                }
                else {
                    first_pair  = dic[j];
                    second_pair = dic[i];
                }
            }
        }
    }

    cout<<first_pair.first<<endl;
    cout<<second_pair.first<<endl;
    
}