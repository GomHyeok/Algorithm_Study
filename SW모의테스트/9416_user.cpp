#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

bool follower[1001][1001];

int timeToPid[1000001];
int timeToUid[1000001];
int postLike[1000001];
int n;

vector<vector<int> > posts;

typedef struct post {
    int timestamp;
    int like;

    bool inTime;

    //작을수록 우선순위가 높음
    bool operator<(const post &r) const {
        //둘다 1000 안에 들어오는 경우
        if(inTime && r.inTime) {
            if(like != r.like) return like > r.like;
            else return timestamp > r.timestamp;
        } else if(!inTime && !r.inTime) return timestamp > r.timestamp;
        else {
            if(inTime) {
                return true;
            }else {
                return false;
            }
        }
    }
}post;

void init(int N)
{
    n = N;
    memset(follower, false, sizeof(follower));
    memset(timeToPid, 0, sizeof(timeToPid));
    memset(postLike, 0, sizeof(postLike));
    memset(timeToUid, 0, sizeof(timeToUid));

    posts.clear();
    posts.resize(N+1);

    for(int i=1; i<=n; i++) {
        follower[i][i] = true;
    }
}

void follow(int uID1, int uID2, int timestamp)
{
    follower[uID1][uID2] = true;
}

void makePost(int uID, int pID, int timestamp)
{
    timeToPid[timestamp] = pID;
    timeToUid[timestamp] = uID;

    posts[uID].push_back(timestamp);

    //오래된 post부터 지워버림
    if(posts[uID].size() > 10) posts[uID].erase(posts[uID].begin());
}

void like(int pID, int timestamp)
{
    postLike[pID]++;
}

void getFeed(int uID, int timestamp, int pIDList[])
{
    priority_queue<post> trueValue; //내림차순 정렬됨 즉 우선 순위가 낮은 놈부터 top에 올라감
    priority_queue<int, vector<int>, greater<int> > falseValue;//타임스템프 작은 것 부터 오름차순 정렬
    
    int i = 1;
    if(timestamp - 1000 > 0) i = timestamp - 1000;

    for(i; i<=timestamp; i++) {
        if(timeToPid[i] <= 0) continue;
        if(!follower[uID][timeToUid[i]]) continue;

        trueValue.push({i, postLike[timeToPid[i]], true});
        if(trueValue.size() > 10) trueValue.pop();
    }


    if(trueValue.size() < 10) {
        for(int i = 1; i<=n ; i++) {
            if(!follower[uID][i]) continue;

            for(int j=0; j<posts[i].size(); j++) {
                if(abs(posts[i][j] - timestamp) <= 1000) continue;

                falseValue.push(posts[i][j]);
                if(falseValue.size() > 10 - trueValue.size()) falseValue.pop();
            }
        }
    }

    while(!falseValue.empty()) {
        int time = falseValue.top();
        falseValue.pop();

        trueValue.push({time, -1, false});
    }

    for(int i = trueValue.size()-1; i>=0; i--) {
        int time = trueValue.top().timestamp;
        trueValue.pop();
        pIDList[i] = timeToPid[time];
    }

    // for(int i=0; i<10; i++) {
    //     cout<<pIDList[i]<<" ";
    // }
    // cout<<endl;
}