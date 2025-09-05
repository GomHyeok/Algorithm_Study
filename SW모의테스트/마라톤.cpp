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

using namespace std;

map<int, vector<int>> spotRoad; //spot이 가진 road
map<int, tuple<int, int, int>> roads;

void init(int N) {
	spotRoad.clear();
	roads.clear();
}

void addRoad(int K, int mID[], int mSpotA[], int mSpotB[], int mLen[]) {
	for(int i=0; i<K; i++) {
		spotRoad[mSpotA[i]].push_back(mID[i]);
		spotRoad[mSpotB[i]].push_back(mID[i]);
		roads[mID[i]] = make_tuple(mSpotA[i], mSpotB[i], mLen[i]);
	}
}

void removeRoad(int mID) {
	if(roads.find(mID) == roads.end()) return;
    auto [a, b, len] = roads[mID];
    roads.erase(mID);

    auto &vec_a = spotRoad[a];
    vec_a.erase(remove(vec_a.begin(), vec_a.end(), mID), vec_a.end());
    auto &vec_b = spotRoad[b];
    vec_b.erase(remove(vec_b.begin(), vec_b.end(), mID), vec_b.end());
}

int getLength(int mSpot) {
	ap<int, vector<pair<int, vector<int>>>> return_spot; // spot -> list of (length, course)
    
    function<void(int, int, set<int>&, vector<int>&)> dfs = [&](int cur_spot, int sum_len, set<int>& visited, vector<int>& course) {
        if(course.size() == 4) {
            return_spot[cur_spot].push_back({sum_len, course});
            return;
        }

        for(int road_id : spot_road[cur_spot]) {
            auto [a, b, len] = roads[road_id];
            int next_spot = a + b - cur_spot; // 양방향
            if(visited.count(road_id) || next_spot == mSpot) continue;

            course.push_back(road_id);
            visited.insert(road_id);
            dfs(next_spot, sum_len + len, visited, course);
            course.pop_back();
            visited.erase(road_id);
        }
    };

    set<int> visited;
    vector<int> course;
    dfs(mSpot, 0, visited, course);

    int max_length = -1;
    for(auto &[s, vec] : return_spot) {
        for(auto &[l1, c1] : vec) {
            set<int> temp_visited(c1.begin(), c1.end());
            for(auto &[l2, c2] : vec) {
                if(l1 + l2 <= 42195) {
                    bool flag = false;
                    for(int road_id : c2) {
                        if(temp_visited.count(road_id)) {
                            flag = true;
                            break;
                        }
                    }
                    if(!flag) max_length = max(max_length, l1 + l2);
                }
            }
        }
    }

    return max_length;
}