#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

struct Monarch {
    string name;
    int allyNum;
    int r;
    int c;
    int soldiers;

    Monarch* next;
};

struct Ally {
    Monarch head;
    Monarch tail;
};

map<int, Ally> allys;
map<int, set<int>> enemy;
map<string, Monarch> monarchs;

int allycnt = 0;

void init(int N, int mSoldier[25][25], char mMonarch[25][25][11])
{
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            allycnt++;
            string name = mMonarch[i][j];
            Monarch monarch = {name, allycnt, i, j, mSoldier[i][j]};
            Ally ally = {monarch, monarch};
            allys[allycnt] = ally;
            enemy[allycnt] = {};
            monarchs[name] = monarch;
        }
    }
}

void destroy()
{

}

int ally(char mMonarchA[11], char mMonarchB[11])
{	
    string namea = mMonarchA;
    string nameb = mMonarchB;
    int allyA = monarchs[namea].allyNum;
    int allyB = monarchs[nameb].allyNum;

    if(allyA == allyB) return -1;

    Ally allyHead = allys[allyA];
    Ally allyTail = allys[allyB];
    allyHead.tail.next = &allyTail.head;
    allyHead.tail = allyTail.tail;

    set<int> enemyB = enemy[allyB];
    set<int> enemyA = enemy[allyA];

    for(auto it : enemyB) {
        enemyA.insert(it);
    }

    enemy[allyA] = enemyA;

    Monarch* node = &allys[allyB].head;

    while(node != nullptr) {
        node -> allyNum = allyA;
        node = node->next;
    }

	return 1;
}

int attack(char mMonarchA[11], char mMonarchB[11], char mGeneral[11])
{
    string nameA = mMonarchA;
    string nameB = mMonarchB;

    int allyA = monarchs[nameA].allyNum;
    int allyB = monarchs[nameB].allyNum;

    int x = monarchs[nameB].r;
    int y = monarchs[nameB].c;

    if(allyA == allyB) return -1;

    int attacker = 0;
    int attackerNodes = 0;
    Monarch* attackerNode = &allys[allyA].head;

    while(attackerNode != nullptr) {
        if(attackerNode-> name == "") {
            attackerNode = attackerNode -> next;
            continue;
        } 

        if(abs(attackerNode->r - x) <= 1 && abs(attackerNode->c - y) <= 1) {
            int soliers = attackerNode -> soldiers / 2;
            attackerNode -> soldiers -= soliers;
            attacker += soliers;
            attackerNodes++;
        }

        attackerNode = attackerNode -> next;
    }

    if(attackerNodes == 0) return -2;

    int dependers = 0;
    Monarch* depender = &allys[allyB].head;

    while(depender != nullptr) {
        if(depender -> name == "") {
            depender = depender -> next;
            continue;
        }

        if(abs(depender->r - x) <= 1 && abs(depender->c - y) <= 1) {
            if(depender -> name == nameB) {
                depender += depender -> soldiers;
            } else {
                int soldiers = depender->soldiers / 2;
                dependers += soldiers;
                depender -> soldiers -= soldiers;
            }
        }

        depender = depender -> next;
    }

    set<int> enemyA = enemy[allyA];
    set<int> enemyB = enemy[allyB];

    enemyA.insert(allyB);
    enemyB.insert(allyA);

    enemy[allyA] = enemyA;
    enemy[allyB] = enemyB;

    if(attacker > dependers) {
        Monarch* origin = &monarchs[nameB];
        Monarch newMonarch = {mGeneral, allyA, origin->r, origin->c, attacker - dependers};

        origin->name = "";

        allys[allyA].tail.next = &newMonarch;
        allys[allyA].tail = newMonarch;
        monarchs[mGeneral] = newMonarch;

        return 1;
    } else {
        monarchs[nameB].soldiers -= attacker;

        return 0;
    }

	return -3;
}

int recruit(char mMonarch[11], int mNum, int mOption)
{
    string name = mMonarch;

    if(mOption == 0) {
        monarchs[name].soldiers += mNum;
    } else {
        int cnt = 0;

        Monarch* monarch = &allys[monarchs[name].allyNum].head;

        while(monarch != nullptr) {
            if(monarch -> name == "") {
                monarch = monarch -> next;
                continue;
            }

            monarch -> soldiers += mNum;

            cnt += monarch -> soldiers;

            monarch = monarch -> next;
        }
        return cnt;
    }

	return -1;
}
