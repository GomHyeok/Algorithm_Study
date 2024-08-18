#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

// 앞쪽 문자열, 가운데 문자열, 뒤쪽 문자열 기준으로
// 원본 문자열에 사전순으로 매핑해주는 map
unordered_map< string, set< string >> mp_fr;
unordered_map< string, set< string >> mp_mid;
unordered_map< string, set< string >> mp_re;

// 각 string의 id를 저장하는 map
unordered_map< string, int > idx;

// 현재 방의 string
string cur_str;

// 각 string id별 방향 정수(2,3,4)
int dir[30010][3];

void init() {
  mp_fr.clear();
  mp_mid.clear();
  mp_re.clear();
  idx.clear();
  cur_str.clear();
  memset(dir, 0, sizeof dir);
}

void addRoom(int mID, char mWord[], int mDirLen[]) {
  string str = mWord;
  idx[str] = mID;
  dir[mID][0] = mDirLen[0];
  dir[mID][1] = mDirLen[1];
  dir[mID][2] = mDirLen[2];

  // str의 각 부분문자열을 key로 하여 map에 저장

  // 앞쪽 길이 2, 4
  mp_fr[str.substr(0, 2)].insert(str);
  mp_fr[str.substr(0, 4)].insert(str);

  // 가운데 길이 3
  mp_mid[str.substr(4, 3)].insert(str);

  // 뒤쪽 길이 2, 4
  mp_re[str.substr(7, 4)].insert(str);
  mp_re[str.substr(9, 2)].insert(str);
}

void setCurrent(char mWord[]) { 
    cur_str = mWord; 
}

int moveDir(int mDir) {
  // 현재 문자열의 ID
  int cur_idx = idx[cur_str];
  // 확인해야 하는 부분 문자열 길이
  int len = dir[cur_idx][mDir];

  string sub;
  if (mDir == 0) {
    // 현재 string의 앞쪽 부분 문자열 구하기
    sub = cur_str.substr(0, len);
    // sub를 뒤쪽 부분 문자열로 가지는 방이 없는 경우
    if (mp_re[sub].empty()) return 0;
    auto it = mp_re[sub].begin();

    // 이동하려는 방이 현재 방인 경우 다음 방으로 이동
    if ((*it) == cur_str) it++;
    // 다음 방이 비어있는 경우
    if (it == mp_re[sub].end()) return 0;

    cur_str = (*it);
    return idx[cur_str];
  } else if (mDir == 1) {
    // 현재 string의 중간 부분 문자열 구하기
    sub = cur_str.substr(4, len);
    // sub를 중간 부분 문자열로 가지는 방이 없는 경우
    auto it = mp_mid[sub].begin();

    // 이동하려는 방이 현재 방인 경우 다음 방으로 이동
    if ((*it) == cur_str) it++;
    // 다음 방이 비어있는 경우
    if (it == mp_mid[sub].end()) return 0;

    cur_str = (*it);
    return idx[cur_str];
  } else {
    // 현재 string의 뒤쪽 부분 문자열 구하기
    sub = cur_str.substr(11 - len, len);
    // sub를 앞쪽 부분 문자열로 가지는 방이 없는 경우
    if (mp_fr[sub].empty()) return 0;
    auto it = mp_fr[sub].begin();

    // 이동하려는 방이 현재 방인 경우 다음 방으로 이동
    if ((*it) == cur_str) it++;
    // 다음 방이 비어있는 경우
    if (it == mp_fr[sub].end()) return 0;

    cur_str = (*it);
    return idx[cur_str];
  }
  return 0;
}

void changeWord(char mWord[], char mChgWord[], int mChgLen[]) {
  string str = mWord;
  string nstr = mChgWord;
  if (str == cur_str) {
    cur_str = nstr;
  }
  int mID = idx[str];

  // 기존 문자열에 대한 정보 제거
  idx.erase(str);

  mp_fr[str.substr(0, 2)].erase(str);
  mp_fr[str.substr(0, 4)].erase(str);
  mp_mid[str.substr(4, 3)].erase(str);
  mp_re[str.substr(7, 4)].erase(str);
  mp_re[str.substr(9, 2)].erase(str);

  // 새로운 문자열에 대한 정보 삽입
  dir[mID][0] = mChgLen[0];
  dir[mID][1] = mChgLen[1];
  dir[mID][2] = mChgLen[2];

  idx[nstr] = mID;

  mp_fr[nstr.substr(0, 2)].insert(nstr);
  mp_fr[nstr.substr(0, 4)].insert(nstr);
  mp_mid[nstr.substr(4, 3)].insert(nstr);
  mp_re[nstr.substr(7, 4)].insert(nstr);
  mp_re[nstr.substr(9, 2)].insert(nstr);
}