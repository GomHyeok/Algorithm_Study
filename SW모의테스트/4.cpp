#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

// 칸의 개수
int n;

// 각 칸에 쌓인 물품 개수
int a[100010];

// 필요한 보호 천막의 크기
int sum;

// 세그먼트 트리의 각 노드에 대한 정보를 저장
struct node {
  // maxv: 현재 구간에서 최댓값
  // Lidx: 현재 구간의 최댓값 중 가장 왼쪽 인덱스
  // Ridx: 현재 구간의 최댓값 중 가장 오른쪽 인덱스
  int maxv, Lidx, Ridx;
} tree[400000];

// 두 자식 노드를 부모 노드로 합치는 함수
node merge(node a, node b) {
  if (a.maxv > b.maxv) return a;
  if (b.maxv > a.maxv) return b;
  return node{a.maxv, a.Lidx, b.Ridx};
}

// point 업데이트
void update(int now, int s, int e, int idx, int val) {
  if (s == e) {
    // 현재 노드가 리프 노드인 경우
    tree[now] = {val, idx, idx};
    return;
  }
  int nl = 2 * now, nr = 2 * now + 1, m = (s + e) / 2;
  if (idx <= m) update(nl, s, m, idx, val);
  else update(nr, m + 1, e, idx, val);

  // 자식 노드를 합쳐서 현재 노드를 갱신
  tree[now] = merge(tree[nl], tree[nr]);
}

// 구간 [qs, qe]의 node 정보를 받는 함수
node Q(int now, int s, int e, int qs, int qe) {
  // 현재 노드가 쿼리 구간에 포함되는 경우
  if (qs <= s && e <= qe) return tree[now];
  // 현재 노드가 쿼리 구간과 겹치지 않는 경우
  if (e < qs || qe < s) return {0, 0, 0};

  int nl = 2 * now, nr = 2 * now + 1, m = (s + e) / 2;

  // 쿼리의 결과를 합쳐서 반환
  return merge(Q(nl, s, m, qs, qe), Q(nr, m + 1, e, qs, qe));
}

// 보호 천막 크기 계산
void calculate() {
  node top = Q(1, 1, n, 1, n);
  // 최댓값 막대기 넓이 계산
  sum = top.maxv * (top.Ridx - top.Lidx + 1);

  // 최댓값 기준 왼쪽, 오른쪽 면적 계산을 위한 인덱스
  int fr = top.Lidx - 1, re = top.Ridx + 1;

  // 최댓값 기준 왼쪽 면적 계산
  while (fr >= 1) {
    // 구간의 최댓값 중 가장 왼쪽을 받아서 넓이 계산
    node tmp = Q(1, 1, n, 1, fr);
    sum += (fr - tmp.Lidx + 1) * tmp.maxv;
    fr = tmp.Lidx - 1;
  }

  // 최댓값 기준 오른쪽 면적 계산
  while (re <= n) {
    // 구간의 최댓값 중 가장 오른쪽을 받아서 넓이 계산
    node tmp = Q(1, 1, n, re, n);
    sum += (tmp.Ridx - re + 1) * tmp.maxv;
    re = tmp.Ridx + 1;
  }
}

void init(int N) {
  n = N;
  sum = 0;

  // 각 노드의 인덱스를 i, 값을 0으로 초기화
  for (int i = 1; i <= n; i++) update(1, 1, n, i, 0);
  memset(a, 0, sizeof a);
}

int stock(int mLoc, int mBox) {
  a[mLoc] += mBox;
  update(1, 1, n, mLoc, a[mLoc]);

  // [1, mLoc-1] 구간 최댓값 계산
  node LL = Q(1, 1, n, 1, mLoc - 1);

  // [mLoc+1, n] 구간 최댓값 계산
  node RR = Q(1, 1, n, mLoc + 1, n);

  // 업데이트 후 mLoc 위치의 물품이
  // 양쪽 구간의 최댓값보다 작은 경우는
  // 넓이 변화가 없음
  if (min(LL.maxv, RR.maxv) > a[mLoc]) return sum;

  calculate();
  return sum;
}

int ship(int mLoc, int mBox) {
  int flag = 0;
  // [1, mLoc-1] 구간 최댓값 계산
  node LL = Q(1, 1, n, 1, mLoc - 1);

  // [mLoc+1, n] 구간 최댓값 계산
  node RR = Q(1, 1, n, mLoc + 1, n);
  if (min(LL.maxv, RR.maxv) > a[mLoc]) flag = 1;

  a[mLoc] -= mBox;
  update(1, 1, n, mLoc, a[mLoc]);

  // 업데이트 전 mLoc 위치의 물품이
  // 양쪽 구간의 최댓값보다 작은 경우는
  // 넓이 변화가 없음
  if (flag == 0) calculate();
  return sum;
}

int getHeight(int mLoc) { return a[mLoc]; }