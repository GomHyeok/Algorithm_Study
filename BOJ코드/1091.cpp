#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int n;
int answer;
vector<int> s;
vector<int> p;
vector<int> card;
map<string, bool> used;

bool check();
void change();

//n card 
//i번 카드 -> s[i]로 이동
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i=0;

    cin>>n;

    for(int i=0; i<n; i++) {
        int pos;
        cin>>pos;
        p.push_back(pos);
    }

    for(int i=0; i<n; i++) {
        int pos;
        cin>>pos;
        s.push_back(pos);
        card.push_back(i);
    }

    while(1) {
        stringstream ss;
        for(int j=0; j<n; j++) {
            ss<<card[j];
        }
        if(used[ss.str()]) {
            cout<<-1<<endl;
            return 0;
        } else {
            used[ss.str()] = true;
        }

        if(check()) {
            cout<<i<<endl;
            return 0;
        }
        change();
        i++;
    }

    cout<<-1<<endl;
}

bool check() {
    for(int i=0; i<n; i++) {
        if(p[card[i]] != i%3) return false;
    }
    return true;
}

void change() {
    vector<int>tmp(n, 0);

    for(int i=0; i<n; i++) {
        tmp[s[i]] = card[i];
    }

    card = tmp;
}