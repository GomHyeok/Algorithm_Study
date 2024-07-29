#include<iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int n, k;
int disk[200001];
int datas[200001];
int answer;
int maxW;

bool possibleValue(int value);

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        maxW = 0;
        cin>>n>>k;

        for(int i=0; i<n; i++) {
            scanf("%d", &disk[i]);
            if(disk[i] > maxW) maxW = disk[i];
        }

        for(int i=0; i<k; i++) {
            scanf("%d", &datas[i]);
        }

        int start = 1;
        int end = maxW;

        while(start <= end) {
            int mid = (start + end) / 2;
            //cout<<mid<<endl;
            if(possibleValue(mid)) {
                end = mid - 1;
                answer = mid;
            } else {
                start = mid + 1;
            }
        }

        printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

bool possibleValue(int value) {
    int nowBlock = 0;

    for(int i=0; i<n; i++) {
        if(disk[i] > value) continue;

        int finalBlock = i + datas[nowBlock];

        for(int j=i; j<finalBlock; j++) {
            if(j >= n) break;

            if(disk[j] > value) {
                i = j;
                break;
            }

            if(j == finalBlock-1) {
                i = j;
                nowBlock++;
            }
        }  
        if(nowBlock == k) return true;
    }

    return false;
}