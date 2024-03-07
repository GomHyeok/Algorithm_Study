#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;
    long long one[21];
    long long lCount = 0;
    long long rCount = 0;
    long long div = 1;
    long long div_r;
    int tmp = n;
    
    one[0] = 1;
    
    for(int i=1; i<=20; i++) {
        one[i] = one[i-1] * 4;
    }
    
    for(int i=1; i<n; i++) {
        div *= 5;
    }
    div_r = div;
    l--;
    
    while(l != 0) {
        long long pos = l/div;
        l %= div;
        div /= 5;
        //cout<<pos<<" "<<l<<endl;
        if(pos >= 3) {
            lCount += (pos-1) * one[n-1];
        } else {
            lCount += pos * one[n-1];
            if(pos == 2) {
                break;
            }
        }
        n--;
    }
    
    while(r != 0) {
        long long pos = r/div_r;
        r %= div_r;
        div_r /= 5;
        //cout<<pos<<" "<<r<<endl;
        if(pos >= 3) {
            rCount += (pos-1) * one[tmp-1];
        } else {
            rCount += pos * one[tmp-1];
            if(pos == 2) {
                break;
            }
        }
        tmp--;
    }
    
    //cout<<lCount<<" "<<rCount<<endl;
    
    answer = rCount - lCount;
    
    return answer;
}