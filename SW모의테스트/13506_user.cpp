#include <iostream>
#include <queue>
#define MAXNUM 1000000
using namespace std;

const int MAX_NUM = 1000000;
extern void putIn(int n, int a);
extern int closeDoor(int n);
extern void arrest(int n);
extern void clearRoom();

void investigate() {
    int roomNumber = 0;
    queue<pair<int, int>> candidates;

    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            int person = i*1000 + j;
            putIn(i, person);
        }
        if(closeDoor(i)) {
            candidates.push({i*1000, i*1000 + 999});
        }
    }

    clearRoom();

    while(!candidates.empty()) {
        int start = candidates.front().first;
        int end = candidates.front().second;
        int mid = (start+end)/2;

        candidates.pop();

        if(roomNumber == MAXNUM) {
            clearRoom();
            roomNumber = 0;
        }

        if(start == end) {
            arrest(start);
            continue;
        }

        for(int i=start; i<=mid; i++) {
            putIn(roomNumber, i);
        }

        if(closeDoor(roomNumber++)) {
            candidates.push({start, mid});
        }

        if(roomNumber == MAXNUM) {
            clearRoom();
            roomNumber = 0;
        }

        for(int i=mid+1; i<=end; i++) {
            putIn(roomNumber, i);
        }

        if(closeDoor(roomNumber++)) {
            candidates.push({mid+1, end});
        }
    }
}