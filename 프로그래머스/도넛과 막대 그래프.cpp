#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int outside[1000001];
int inside[1000001];
vector<int> path[1000001];
int donut;
int stick;
int eight;

void check(int start);

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    for(int i=0; i<edges.size(); i++) {
        outside[edges[i][0]]++;
        inside[edges[i][1]]++;
        path[edges[i][0]].push_back(edges[i][1]);
    }
    
    for(int i=0; i<=1000000; i++) {
        if(inside[i] == 0 && outside[i] >= 2) {
            answer.push_back(i);
            break;
        }
    }
    
    for(int i=0; i < path[answer[0]].size(); i++) {
        check(path[answer[0]][i]);
    }
    
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    
    return answer;
}

void check(int start) {
    queue<int> q;
    q.push(start);
    bool visited[1000001];
    memset(visited, 0, 1000001);
    
    visited[start] = true;
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        if(outside[now] >= 2) {
            eight++;
            return;
        }
        
        for(int i=0; i<path[now].size(); i++) {
            if(visited[path[now][i]]) {
                donut++;
                return;
            }
            visited[path[now][i]] = true;
            q.push(path[now][i]);
        }
    }
    stick++;
    return;
}