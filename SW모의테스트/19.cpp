#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <queue>

#define MAXN 100000

using namespace std;

long long segment[MAXN * 4 + 1000];
long long n;
long long arr[MAXN + 1000];

vector<vector<long long> > indices;

void startSeg(int now, int start, int last) {
    if (start == last) {
        segment[now] = arr[start];
        return;
    } else {
        int leftn = 2 * now;
        int rightn = 2 * now + 1;
        int mid = (start + last) / 2;

        startSeg(leftn, start, mid);
        startSeg(rightn, mid + 1, last);

        segment[now] = segment[leftn] + segment[rightn];
    }
}

long long sumValue(int now, int start, int last, int answerS, int answerE) {
    if(answerS <= start && last <= answerE) {
        return segment[now];
    } else {
        if(last < answerS || answerE < start) return 0;
        else {
            int leftn = 2 * now;
            int rightn = 2* now + 1;
            int mid = (start + last) / 2;
            return sumValue(leftn, start, mid, answerS, answerE) + sumValue(rightn, mid+1, last, answerS, answerE);
        }
    }
}

void updateValue(int now, int start, int last,  int index, int value) {
    if ( start == last) {
        segment[now] = value;
        return;
    }

    int leftn = 2 * now;
    int rightn = 2* now + 1;
    int mid = (start + last) / 2;

    if(index <= mid) {
        updateValue(leftn, start, mid, index, value);
    } else {
        updateValue(rightn, mid + 1, last, index, value);
    }

    segment[now] = segment[leftn] + segment[rightn];
}

void init(int N, int M, int mType[], int mTime[]) {
    n = N - 1;
    memset(segment, 0, sizeof(segment));
    memset(arr, 0, sizeof(arr));

    indices.assign(1010, {});

    for(int i=0; i<=N - 2; i++) {
        indices[mType[i]].push_back(i+1);
    }
    for(int i=0; i<=N-2; i++) {
        arr[i+1] = mTime[i];
    }

    startSeg(1, 1, n);
}

//구현할 필요 없음
void destroy() {
}

void update(int mID, int mNewTime) {
    arr[mID + 1] = mNewTime;
    updateValue(1, 1, n, mID + 1, mNewTime);
}

int updateByType(int mTypeID, int mRatio256) {
    long long tmp = 0;
    for(int i=0; i< indices[mTypeID].size(); i++) {
        int idx = indices[mTypeID][i];
        arr[idx] = arr[idx] * mRatio256 / 256;
        tmp += arr[idx];
        updateValue(1, 1, n, idx, arr[idx]);
    }
    return tmp;  
}

int calculate(int mA, int mB) {
    return sumValue(1, 1, n, min(mA + 1, mB + 1), max(mA + 1, mB + 1)-1);
}
