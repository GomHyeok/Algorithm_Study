#include <iostream>
#include <vector>

using namespace std;

//문제 상황
//질량 1~N (납, 주석) -> 각각 1개씩만 있음
//납 + 주석(각 1개) -> 2의 거듭제곱 츄 N개 만드려고함
//n <= 10000
//1:1 matching

//이미 사용한 추인지 검증
bool used[10001];


int main() {
    int n;
    vector<int> answer;
    long long pos = 1;

    cin>>n;
    answer.resize(n+1);

    //추 2개를 합쳤을 때 최대 무게 = 2*n
    //따라서 가능한 최대 2의 거듭 제곱은 2*n보다 작다.
    while(1) {
        if(pos * 2 > 2*n) break;
        pos*=2;
    }

    //추의 무개가 클 수록 가능한 경우의 수가 줄어 뒤에서 부터 하는게 유리하다고 판단.
    for(int i=n; i>0; i--) {
        //가능한 2의 거듭 제곱에 대하여 사용가능한 추가 있는지 검증
        for(int j=pos; j>=2; j/=2) {
            if(j-i <= 0 || j-i > n) continue;
            if(used[j-i]) continue;

            used[j-i] = true;
            answer[i] = j-i;
            break;
        }
    }

    for(int i=1; i<=n; i++) {
        cout<<answer[i]<<endl;
    }
}

//정답 설명
/*
n의 수를 1에서부 키우면서 생각
1 
1
1 2
1 2
1 2 3
3 2 1
1 2 3 4
3 2 1 4
1 2 3 4 5
1 2 5 4 3
n의 수를 점차 키우다 보니 현재 추의 무개가 클 수록 가능한 경우의 수가 적다는 것을 판단.
그렇다면 추의 무개를 점차 줄여가며 가능한 무개를 찾으면 시간 복잡도가 줄어들 것으로 판단.
시간복잡도의 경우 n~1 -> n 2의 거듭제곱 최대 ~ 1 -> log(n)
따라서 최악의 시간복잡도는 nlog(n) -> n의 최대 값이 10000이기 때문에 시간복잡도에서 문제가 없을 것으로 판단.
*/