#include <unordered_map>
#include <vector>
using namespace std;
 
 
#define MAX_TIME 2000000
#define MAX_LAZY ((MAX_TIME / 100) * 4)
 
 
struct WORKER {
    int active;
    int start, end;
 
 
    void init(int mid, int mstart, int mend) {
        active = 1;
        start = mstart;
        end = mend;
    }
};
 
 
struct {
    int cnt;
    vector <WORKER*> starts;
    vector <WORKER*> ends;    
} Schedule[MAX_TIME / 100 + 1];
 
 
WORKER worker[5000];
int wcnt;
 
 
int lazyCnt[MAX_LAZY];
int workCnt[MAX_LAZY];
 
 
unordered_map<int, int> wIDs;
int mTime, maxLazy;
 
 
void init(int musicTime)
{
    wIDs.clear();
    wcnt = 0;
 
 
    mTime = musicTime;
    maxLazy = MAX_TIME / mTime;
 
 
    for (int i = 0; i <= maxLazy; i++) {
        Schedule[i].cnt = 0;
        Schedule[i].ends.clear();
        Schedule[i].starts.clear();
    }
 
 
    for (int i = 0; i < MAX_LAZY; i++) {
        lazyCnt[i] = 0;
        workCnt[i] = 0;
    }
}
 
 
void lazyprop(int node, int st, int en) {
    if (lazyCnt[node]) {
        workCnt[node] += (en - st + 1) * lazyCnt[node];
        if (st != en) {
            lazyCnt[node * 2] += lazyCnt[node];
            lazyCnt[node * 2 + 1] += lazyCnt[node];
        }
        lazyCnt[node] = 0;
    }
}
 
 
void lazy(int node, int st, int en, int left, int right, int val)
{
    lazyprop(node, st, en);
    if (left > en || right < st) return;
 
 
    if (left <= st && en <= right) {
        workCnt[node] += (en - st + 1) * val;
        if (st != en) {
            lazyCnt[node * 2] += val;
            lazyCnt[node * 2 + 1] += val;
        }
        return;
    }
    int mid = (st + en) / 2;
    lazy(node * 2, st, mid, left, right, val);
    lazy(node * 2 + 1, mid + 1, en, left, right, val);
    workCnt[node] = workCnt[node * 2] + workCnt[node * 2 + 1];
}
 
 
void remove_worker(WORKER *p)
{
    p->active = 0;
 
 
    int start = p->start / mTime + 1;
    int end = p->end / mTime - 1;
    lazy(1, 1, maxLazy, start, end, -1);
}
 
 
void add(int mID, int mStart, int mEnd)
{
    if (wIDs.find(mID) != wIDs.end()) {
        int idx = wIDs[mID];
        remove_worker(&worker[idx]);
    }
 
 
    WORKER *w = &worker[wcnt];
    wIDs[mID] = wcnt;
    wcnt++;
 
 
    w->init(mID, mStart, mEnd);
 
 
    int start = mStart / mTime;
    Schedule[start].starts.push_back(w);
    start++;
 
 
    int end = mEnd / mTime;
    Schedule[end].ends.push_back(w);
    end--;
 
 
    lazy(1, 1, maxLazy, start, end, 1);
}
 
 
void remove(int mID)
{
    if (wIDs.find(mID) == wIDs.end()) return;
 
 
    int idx = wIDs[mID];
    wIDs.erase(mID);
 
 
    WORKER *w = &worker[idx];
    remove_worker(w);
}
 
 
int get_lazycnt(int node, int st, int en, int idx)
{
    lazyprop(node, st, en);
    if (idx > en || idx < st) return 0;
 
 
    if (st == en) {
        return workCnt[node];
    }
 
 
    int mid = (st + en) / 2;
    if (idx <= mid)
        return get_lazycnt(node * 2, st, mid, idx);
    return get_lazycnt(node * 2 + 1, mid + 1, en, idx);
}
 
 
int getCnt(int mBSTime)
{
    int cnt = get_lazycnt(1, 1, maxLazy, mBSTime / mTime);
 
 
    for (WORKER *w : Schedule[mBSTime / mTime].starts) {
        if (w->active == 0) continue;
        if (w->start <= mBSTime) cnt++;
    }
 
 
    int etime = mBSTime + mTime;
    for (WORKER *w : Schedule[mBSTime / mTime + 1].ends) {
        if (w->active == 0) continue;
        if (w->end < etime) cnt--;
    }
 
 
    return cnt;
}
 