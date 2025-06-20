#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[11][11];
bool visited[11][1<<11];
int n;
int answer = 987654321;

struct Node {
    int cur, channel, start, dist;
    bool operator<(const Node& b) const {
        return dist> b.dist;
    }
};

int main() {
    priority_queue<Node> pq;

    cin>>n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>board[i][j];
        }
        pq.push({i, 1<<i, i, 0});
    }

    while(!pq.empty()) {
        int cur = pq.top().cur;
        int channel = pq.top().channel;
        int start = pq.top().start;
        int dist = pq.top().dist;

        pq.pop();

        visited[cur][channel] = true;

        if(channel == (1<<n) - 1 && board[cur][start] != 0) {
            answer = min(answer, dist + board[cur][start]);
        }

        for(int i=0; i<n; i++) {
            if(board[cur][i] > 0 && !visited[cur][channel | (1<<i)]) {
                pq.push({i, channel | (1<<i), start, dist + board[cur][i]});
            }
        }
    }

    cout<<answer<<endl;
}