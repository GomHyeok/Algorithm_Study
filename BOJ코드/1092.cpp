#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>

using namespace std;

int n;
int m;

vector<int> boxs;
vector<int> crain;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int answer = 0;
    int box = 0;
    cin>>n;

    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        crain.push_back(tmp);
    }

    sort(crain.begin(), crain.end(), compare);

    cin>>m;
    
    for(int i=0; i<m; i++) {
        int tmp;
        cin>>tmp;
        boxs.push_back(tmp);
    }

    sort(boxs.begin(), boxs.end(), compare);

    if(crain[0] < boxs[0]) {
        cout<<-1<<endl;
        return 0;
    }

    while(box != m) {
        answer++;
        int index = 0;

        for(int i=0; i<m; i++) {
            if(boxs[i] == 0) continue;
            if(index == n) break;
            if(boxs[i] <= crain[index]) {
                index++;
                box++;
                boxs[i] = 0;
            }
        }
    }

    cout<<answer<<endl;
}