#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N);
extern void addRoad(int K, int mID[], int mSpotA[], int mSpotB[], int mLen[]);
extern void removeRoad(int mID);
extern int getLength(int mSpot);

#define CMD_INIT	100
#define CMD_ADD		200
#define CMD_REMOVE	300
#define CMD_GETLEN	400

static bool run()
{
	int Q, N, K;
	int id[10], sa[10], sb[10], len[10];
	char strTmp[30];
	int ret, ans;

	bool ok = false;

	scanf("%d", &Q);
	for (int q = 0; q < Q; q++)
	{
		int cmd;
		scanf("%d", &cmd);
		if (cmd == CMD_INIT)
		{
			scanf("%d", &N);
			init(N);
			ok = true;
		}
		else if (cmd == CMD_ADD)
		{
			scanf("%s %d", strTmp, &K);
			for (int i = 0; i < K; i++) {
				scanf("%s %d %s %d %s %d %s %d", strTmp, &id[i], strTmp, &sa[i], strTmp, &sb[i], strTmp, &len[i]);
			}
			addRoad(K, id, sa, sb, len);
		}
		else if (cmd == CMD_REMOVE)
		{
			scanf("%s %d", strTmp, &id[0]);
			removeRoad(id[0]);
		}
		else if (cmd == CMD_GETLEN)
		{
			scanf("%s %d", strTmp, &id[0]);
			ret = getLength(id[0]);
			scanf("%s %d", strTmp, &ans);
			if (ans != ret) {
				ok = false;
			}
		}
		else ok = false;
	}
	return ok;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <map>

//start == end
//8개 도로
//반환 지점 = 도로 4개 사용하고
//출발 도착 지점은 중건 지점으로 사용할 수 없다.

using namespace std;

map<int, pair<int, int>> road;
map<int, int> roadLen;
vector<map<int, int>> roads; // 최대 5지점

int answer = 0;
int start = 0;

void dfs(int spot, int cnt, int sum, set<int>& usedRoads);

void init(int N)
{
    roads.resize(N + 1);
}

//최대 1000
void addRoad(int K, int mID[], int mSpotA[], int mSpotB[], int mLen[])
{
    for(int i=0; i<K; i++) {
        int a = mSpotA[i];
        int b = mSpotB[i];
        int id = mID[i];
        int len = mLen[i];

        road[id] = {a, b};
        roadLen[id] = len;
        roads[a][b] = id;
        roads[b][a] = id;
    }
}

//max 100
void removeRoad(int mID)
{
    int a = road[mID].first;
    int b = road[mID].second;
    road.erase(mID);
    roadLen.erase(mID);
    roads[a].erase(b);
    roads[b].erase(a);
}

//max 1000
int getLength(int mSpot)
{
    answer = -1;
    start = mSpot;
    set<int> used;

    dfs(mSpot, 0, 0, used);
	return answer;
}

void dfs(int spot, int cnt, int sum, set<int>& usedRoads) {
    if(sum >42195) { return; }
    if(cnt >= 8) {
        if(start == spot) { answer = max(sum, answer); }
        return;
    }

    for(auto& it : roads[spot]) {
        int nextSpot = it.first;
        int roadID = it.second;
        int len = roadLen[roadID];

        if(usedRoads.count(roadID)) continue;
        if(nextSpot == start && cnt < 7) continue;

        usedRoads.insert(roadID);
        dfs(nextSpot, cnt+1, sum + len, usedRoads);
        usedRoads.erase(roadID);
    }
}