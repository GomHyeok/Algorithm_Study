#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[51];
int answer;
vector<int> truth;
vector<vector<int>> parties;

int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionGroup(int a, int b) {
    int rootA = findParent(a);
    int rootB = findParent(b);
    if (rootA != rootB) {
        parent[rootB] = rootA;
    }
}

bool isConnected(int a, int b) {
    return findParent(a) == findParent(b);
}

void solve() {
    cin >> n >> m;
    
    // 초기 부모는 자기 자신
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int truthCount;
    cin >> truthCount;

    for (int i = 0; i < truthCount; i++) {
        int person;
        cin >> person;
        truth.push_back(person);
    }

    for (int i = 0; i < m; i++) {
        int partySize;
        cin >> partySize;
        vector<int> party;

        for (int j = 0; j < partySize; j++) {
            int person;
            cin >> person;
            party.push_back(person);
        }

        // 같은 파티의 사람들끼리 Union
        for (int j = 1; j < party.size(); j++) {
            unionGroup(party[0], party[j]);
        }

        parties.push_back(party);
    }

    answer = m;

    // 각 파티의 구성원이 진실을 아는 사람과 연결되어 있는지 확인
    for (const auto& party : parties) {
        for (int person : party) {
            for (int knower : truth) {
                if (isConnected(person, knower)) {
                    answer--;
                    goto nextParty;
                }
            }
        }
    nextParty:;
    }

    cout << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
