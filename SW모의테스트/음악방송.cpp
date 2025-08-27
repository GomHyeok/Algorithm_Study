#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int playTime;

map<int, pair<int, int>> employee;

void init(int musicTime)
{
    playTime = musicTime;
}

//최대 5000번
void add(int mID, int mStart, int mEnd)
{
    employee[mID] = {mStart, mEnd};
}

//최대 500번
void remove(int mID)
{
    employee.erase(mID);
}

//최대 30000번
int getCnt(int mBSTime)
{
	return 0;
}