#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define	MAXL			5
#define MAXF			10

extern void init(int N);
extern void add(int id, int F, int ids[MAXF]);
extern void del(int id1, int id2);
extern int  recommend(int id, int list[MAXL]);

#define INIT			1
#define ADD				2
#define DEL				3
#define RECOMMEND		4

static int N, M;

static bool run()
{
	int cmd;
	int id, F, ids[MAXF];
	int id1, id2;
	int len, len_a;
	int list[MAXL], list_a[MAXL];
	
	bool okay;

	okay = false;

	scanf("%d", &M);

	for (int k = 0; k < M; ++k)
	{
		scanf("%d", &cmd);
		switch(cmd)
		{
		case INIT:
			scanf("%d", &N);
			init(N);
			okay = true;
			break;
		case ADD:
			scanf("%d %d", &id, &F);
			for (int i = 0; i < F; ++i)
				scanf("%d", &ids[i]);
			if (okay)
				add(id, F, ids);
			break;
		case DEL:
			scanf("%d %d", &id1, &id2);
			if (okay)
				del(id1, id2);
			break;
		case RECOMMEND:
			scanf("%d %d", &id, &len_a);
			for (int i = 0; i < len_a; ++i)
				scanf("%d", &list_a[i]);
			if (okay)
			{
				len = recommend(id, list);
				if (len != len_a)
					okay = false;

				for (int i = 0; okay && i < len_a; ++i)
					if (list[i] != list_a[i])
						okay = false;
			}
			break;
		}
	}
	
	return okay;
}

int main()
{
	int TC, MARK;
	
    //freopen("sample_input.txt", "r", stdin);

	setbuf(stdout, NULL);
    scanf("%d %d", &TC, &MARK);

    for (int testcase = 1; testcase <= TC; ++testcase)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", testcase, score);
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define MAXL	5
#define MAXF	10

using namespace std;

unordered_map <int, unordered_set<int>> friends;

void init(int N)
{
	friends.clear();
}

void add(int id, int F, int ids[MAXF])
{
    for(int i=0; i<F; i++) {
        int fid = ids[i];
        friends[id].insert(fid);
        friends[fid].insert(id);
    }
}

void del(int id1, int id2)
{
    friends[id1].erase(id2);
    friends[id2].erase(id1);
}

int recommend(int id, int list[MAXL])
{
    unordered_map<int, int> friendCount;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ids;
    int count = 0;

    for(int fid : friends[id]) { //기준 id
        for(int otherID : friends[fid]) { //비교 id(이미 친구임)
            if(otherID != id && friends[id].find(otherID) == friends[id].end())//본인이 아니고 친구가 아니면 해당 id의 중복 친국가 추가됨(비교 id가 중복 친구)
                friendCount[otherID]++;
        }
    }



    for(auto iter : friendCount) {
        pq.push({-iter.second, iter.first});
    }

    while(!pq.empty() && count < MAXL) {
        ids.push_back(pq.top().second);
        pq.pop();
        count++;
    }

    for(int i=0; i<ids.size(); i++) {
        list[i] = ids[i];
    }

	return ids.size();
}