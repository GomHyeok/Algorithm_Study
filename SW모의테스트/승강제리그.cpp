#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void print();
void sortMove();
void sortTrade();

struct Player {
    int id;
    int ability;

    Player(int id, int ability) {
        this->id = id;
        this->ability = ability;
    }
};

int n, l, m;
vector<vector<Player*>> leaguePlayer;

bool compare(Player* a, Player* b) {
    return a->ability > b->ability;
}

void init(int N, int L, int mAbility[]) {
    n = N;
    l = L;
    m = n/l;
    for(int i=0; i<l; i++) {
        vector<Player*> tmp;
        for(int j=0; j<m; j++) {
            int pos = m*i + j;
            tmp.push_back(new Player(pos, mAbility[pos]));
        }
        sort(tmp.begin(), tmp.end(), compare);
        leaguePlayer.push_back(tmp);
    }
}

int move() {
    vector<bool> isMoved(n, false);
    int player = 0;

    for(int i=0; i<l-1; i++) {
        Player* best = leaguePlayer[i+1][0];
        leaguePlayer[i + 1][0] = leaguePlayer[i][m-1];
        leaguePlayer[i][m-1] = best;
        if(!isMoved[leaguePlayer[i][m-1]->id]) {
            player += leaguePlayer[i][m-1]->id;
            isMoved[leaguePlayer[i][m-1]->id] = true;
        }

        if(!isMoved[leaguePlayer[i+1][0]->id]) {
            player += leaguePlayer[i+1][0]->id;
            isMoved[leaguePlayer[i+1][0]->id] = true;
        }
    }
    sortMove();
    cout<<player<<endl;
    return player;
}

int trade() {
    vector<bool> isMoved(n, false);
    int player = 0;
    int pos = (m+1)/2;

    for(int i=0; i<l-1; i++) {
        Player* middle = leaguePlayer[i][pos];
        leaguePlayer[i][pos] = leaguePlayer[i+1][0];
        leaguePlayer[i+1][0] = middle;

        if(!isMoved[leaguePlayer[i][pos]->id]) {
            player += leaguePlayer[i][pos] -> id;
            isMoved[leaguePlayer[i][pos] -> id] = true;
        }

        if(!isMoved[leaguePlayer[i+1][0]->id]) {
            player += leaguePlayer[i+1][0]->id;
            isMoved[leaguePlayer[i+1][0] -> id] = true;
        }
    }
    sortTrade();
    cout<<player<<endl;
    return player;
}

void sortMove() {
    for(int i=0; i<l; i++) {
        int pos = 0;
        for(int j=1; j<m-1; j++) {
            if(leaguePlayer[i][pos]->ability >= leaguePlayer[i][j]->ability) break;
            //cout<<pos<<" "<<leaguePlayer[i][pos] -> id<<" "<<leaguePlayer[i][pos]->ability<<" -> "<<j<<" "<<leaguePlayer[i][j]->id<<" "<<leaguePlayer[i][j]->ability<<endl;
            Player* p = leaguePlayer[i][pos];
            leaguePlayer[i][pos] = leaguePlayer[i][j];
            leaguePlayer[i][j] = p;
            pos = j;
        }

        pos = m-1;
        for(int j=m-2; j>=0; j--) {
            if(leaguePlayer[i][pos]->ability <= leaguePlayer[i][j]->ability) break;
            //cout<<pos<<" "<<leaguePlayer[i][pos] -> id<<" "<<leaguePlayer[i][pos]->ability<<" -> "<<j<<" "<<leaguePlayer[i][j]->id<<" "<<leaguePlayer[i][j]->ability<<endl;
            Player* p = leaguePlayer[i][pos];
            leaguePlayer[i][pos] = leaguePlayer[i][j];
            leaguePlayer[i][j] = p;
            pos = j;
        }
    }
}

void sortTrade() {
    for(int i=0; i<l; i++) {
        int pos = (m+1)/2;
        for(int j=pos-1; j>0; j--) {
            if(leaguePlayer[i][pos]->ability <= leaguePlayer[i][j]->ability) break;

            Player* p = leaguePlayer[i][pos];
            leaguePlayer[i][pos] = leaguePlayer[i][j];
            leaguePlayer[i][j] = p;
            pos = j;
        }

        for(int j=pos+1; j<m; j++) {
            if(leaguePlayer[i][pos]->ability >= leaguePlayer[i][j]->ability) break;

            Player* p = leaguePlayer[i][pos];
            leaguePlayer[i][pos] = leaguePlayer[i][j];
            leaguePlayer[i][j] = p;
            pos = j;
        }

        pos=0;
        for(int j=1; j<m; j++) {
            if(leaguePlayer[i][pos]->ability >= leaguePlayer[i][j]->ability) break;

            Player* p = leaguePlayer[i][pos];
            leaguePlayer[i][pos] = leaguePlayer[i][j];
            leaguePlayer[i][j] = p;
            pos = j;
        }
    }
}

void print() {

    for(int i=0; i<l; i++) {
        cout<<"league num : "<<i<<" "<<endl;
        for(int j=0; j<m; j++) {
            Player* p = leaguePlayer[i][j];
            cout<<p->id<<" "<<p->ability<<endl;
        }
        cout<<endl;
    }
}





















#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

void init(int N, int L, int mAbility[]);
int move();
int trade();

#define MAX_N 39990

#define CMD_INIT 100
#define CMD_MOVE 200
#define CMD_TRADE 300

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ans;
    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);
        if (query == CMD_INIT)
        {
            int N;
            int L;
            int mAbility[MAX_N];
            scanf("%d %d", &N, &L);
            for (int i = 0; i < N; i++){
                scanf("%d", &mAbility[i]);
            }
            init(N, L, mAbility);
            ok = true;
        }
        else if (query == CMD_MOVE)
        {
            int ret = move();
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
        else if (query == CMD_TRADE)
        {
            int ret = trade();
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
    // freopen("sample_input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}