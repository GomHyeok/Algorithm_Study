#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int n, c;
int answer;
vector<long long> house;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>c;

    for(int i=0; i<n; i++) {
        long long num;
        cin>>num;
        house.push_back(num);
    }

    sort(house.begin(), house.end());

    int minDist = 1;
    int maxDist = house[n-1] - house[0];

    while(minDist <= maxDist) {
        int midDist = (minDist + maxDist)/2;//최대 거리가 될 수 있는 값

        int cnt = 1;//공유기 설치 개수
        int prev = house[0];//첫번째 집에는 무조건 설치되어야함 + 현재 위치
        for(int i=1; i<n; i++) {
            if(house[i] - prev >= midDist) {//최대 거리 이상 벌어진 집에 설치
                cnt++;
                prev = house[i];//기준 집 위치 변경
            }
        }

        if(cnt >= c) {//개수 충분히 설치한 경우
            answer = max(answer, midDist);
            minDist = midDist + 1;//최소값을 변경
        }
        else maxDist = midDist -1;
    }

    cout<<answer<<endl;

}