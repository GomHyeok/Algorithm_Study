#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// int parent[20000];
// int childCnt[20000];
// int N;

// vector<set<int>> child(20000);
// vector<string> names(20000, "");
// unordered_map<string, int> indexs;
// priority_queue<int, vector<int>, greater<int>> useable;

// void printValues() {
//     cout<<"child : "<<endl;
//     for(int i=0; i<child.size(); i++) {
//         if(child[i].size() > 0) {
//             cout<<i<<" ";
//             for(auto iter : child[i]) {
//                 cout<<iter<<" ";
//             }
//             cout<<endl;
//         }
//     }
//     cout<<endl;

//     cout<<"names"<<endl;
//     for(int i=0; i<names.size(); i++) {
//         if(names[i] != "") {
//             cout<<names[i]<<" ";
//         }
//     }
//     cout<<endl;

//     cout<<"indexs : "<<endl;
//     for(auto iter : indexs) {
//         cout<<iter.first<<" "<<iter.second<<endl;
//     }

//     cout<<"cnt : "<<endl;
//     for(int i=0; i<=N; i++) {
//         cout<<childCnt[i]<<" ";
//     }
//     cout<<endl;
// }

// void rmDfs(int idx) {
//     if(childCnt[idx] != 0) {
//         for(auto iter : child[idx]) {
//             rmDfs(iter);
//         }
//         child[idx].clear();
//     }
//     parent[idx] = 0;
//     childCnt[idx] = 0;
//     names[idx] = "";
//     useable.push(idx);
// }

// void cpDfs(string childName, string parentName) {
//     string dir = "";
//     string tmp = "";
//     for(int i = childName.size() - 1; i>=0; i--) {
//         if(childName[i] == '/') break;
//         dir = childName[i] + dir;
//     }

//     dir = parentName + dir;

//     if(parentName.size() > 1) {
//         parentName.erase(parentName.size()-1);
//     }

//     int idx = indexs[childName];
//     int pIdx = indexs[parentName];

//     indexs[dir] = useable.top();
//     useable.pop();
//     names[indexs[dir]] = dir;
//     child[pIdx].insert(indexs[dir]);
//     parent[indexs[dir]] = pIdx;
//     if(childCnt[idx] != 0) {
//         for(auto iter : child[idx]) {
//             dir+="/";
//             cpDfs(names[iter], dir);
//         }
//     }
// }

// void init(int n) {
//     N = n;
//     useable = priority_queue<int, vector<int>, greater<int>>();
//     for(int i=0; i<n; i++) {
//         parent[i] = 0;
//         childCnt[i] = 0;
//         child[i].clear();
//         names[i] = "";
//     }
//     for(int i=1; i<200000; i++) {
//         useable.push(i);
//     }
//     indexs.clear();
//     names[0] = "/";
//     indexs["/"] = 0;
// }

// void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
//     vector<string> paths;
//     paths.push_back("/");
//     string st = path;
//     string tmp = "/";
//     for(int i=1; i<st.size(); i++) {
//         if(st[i] == '/') {
//             paths.push_back(tmp);
//             tmp+=st[i];
//             continue;
//         }
//         tmp+=st[i];
//     }

//     for(int i=0; i<paths.size(); i++) {
//         int idx = indexs[paths[i]];
//         childCnt[idx]++;
//         if(i == paths.size()-1) {
//             int use = useable.top();
//             useable.pop();
//             string dir = name;
//             if(paths[i] != "/") dir = paths[i] + "/" + name;
//             else  dir = paths[i] + name;
//             names[use] = dir;
//             indexs[dir] = use;
//             parent[use] = idx;
//             child[idx].insert(use);
//         }
//     }

//     printValues();
// }

// void cmd_rm(char path[PATH_MAXLEN + 1]) {
//     vector<string> paths;
//     paths.push_back("/");
//     string st = path;
//     string tmp = "/";
//     for(int i=1; i<st.size(); i++) {
//         if(st[i] == '/') {
//             paths.push_back(tmp);
//             tmp+=st[i];
//             continue;
//         }

//         tmp+=st[i];
//     }
//     int rmIdx = indexs[paths[paths.size()-1]];

//     for(int i=0; i<paths.size(); i++) {
//         int idx = indexs[paths[i]];
//         childCnt[idx]-=(childCnt[rmIdx]+1);
//         if(i != paths.size()-1) {
//             //cout<<paths[i]<<" "<<childCnt[indexs[paths[i]]]<<endl;
//             auto iter = child[idx].find(rmIdx);
//             if(iter != child[idx].end()) child[idx].erase(iter);
//         }
//     }
//     rmDfs(rmIdx);
//     printValues();
// }

// void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
//     vector<string> paths;
//     paths.push_back("/");
//     string st = srcPath;
//     string tmp = "/";
//     for(int i=1; i<st.size(); i++) {
//         if(st[i] == '/') {
//             paths.push_back(tmp);
//             tmp+=st[i];
//             continue;
//         }
//         tmp+=st[i];
//     }

//     vector<string> path;
//     path.push_back("/");
//     st = dstPath;
//     tmp = "/";
//     for(int i=1; i<st.size(); i++) {
//         if(st[i] == '/') {
//             path.push_back(tmp);
//             tmp+=st[i];
//             continue;
//         }
//         tmp+=st[i];
//     }

//     for(int i=0; i<path.size(); i++) {
//         childCnt[indexs[path[i]]] += (childCnt[indexs[paths[paths.size()-1]]] + 1);
//     }

//     cpDfs(paths[paths.size()-1], dstPath);

//     printValues();
// }

// void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
//     cmd_cp(srcPath, dstPath);
//     cmd_rm(srcPath);

//     //printValues();
// }

// int cmd_find(char path[PATH_MAXLEN + 1]) {
//     string st = path;
//     if(st.size() > 1) {
//         st.erase(st.end()-1);
//     }
//     cout<<childCnt[indexs[st]]<<endl;
// 	return childCnt[indexs[st]];
// }


#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int parent[200000];
int childCnt[200000];
int N;

vector<set<int>> child;
vector<string> names;
queue<int> useable;

int getIdx(char path[PATH_MAXLEN + 1]) {
    int ret = 0;
    char *ptr = strtok(path, "/");
    while (ptr != NULL) {
        for (auto i : child[ret]) {
        if (names[i] == ptr) {
            ret = i;
            break;
        }
        }
        ptr = strtok(NULL, "/");
    }
    return ret;
}

void sumCnt(int now, int cnt) {
    childCnt[now] += cnt;
    if(parent[now] != -1) {
        sumCnt(parent[now], cnt);
    }
}

void rmCmd(int idx) {
    for(auto iter : child[idx]) {
        rmCmd(iter);
    }
    child[idx].clear();
    useable.push(idx);
    parent[idx] = -1;
    childCnt[idx] = 0;
}

int cpCmd(int from, int to) {
    int nextIdx = useable.front();
    useable.pop();

    childCnt[nextIdx] = childCnt[from];
    names[nextIdx] = names[from];

    for(auto iter : child[from]) {
        int childIdx = cpCmd(iter, nextIdx);
        child[nextIdx].insert(childIdx);
    }

    parent[nextIdx] = to;
    return nextIdx;
}

void init(int n) {
    N = n;
    useable = queue<int>();
    memset(childCnt, 0, sizeof(childCnt));
    memset(parent, -1, sizeof(parent));
    child.clear();
    names.clear();
    child.resize(n+1);
    names.resize(n+1);

    for(int i=0; i<n; i++) {
        useable.push(i+1);
    }

    childCnt[0] = 1;
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
    string st = path;
    string tmp = "";
    int idx = 0;
    int nextIdx = useable.front();
    useable.pop();
    idx = getIdx(path);

    childCnt[nextIdx] = 1;
    names[nextIdx] = name;
    child[idx].insert(nextIdx);
    parent[nextIdx] = idx;
    sumCnt(idx, childCnt[nextIdx]);
    //printValue();
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
    string st = path;
    string tmp = "";
    int idx = 0;
    idx = getIdx(path);
    if(parent[idx] != -1) {
        sumCnt(parent[idx], -childCnt[idx]);
        child[parent[idx]].erase(idx);
    }
    parent[idx] = -1;

    rmCmd(idx);
    //printValue();
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
    string st = srcPath;
    string tmp = "";
    int from = getIdx(srcPath);

    st = dstPath;
    tmp = "";
    int to = getIdx(dstPath);
    int nextIdx = cpCmd(from, to);
    sumCnt(to, childCnt[nextIdx]);
    child[to].insert(nextIdx);
    //printValue();
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
    string st = srcPath;
    string tmp = "";
    int from = getIdx(srcPath);

    st = dstPath;
    tmp = "";
    int to = getIdx(dstPath);

    if(parent[from] != -1) {
        sumCnt(parent[from], -childCnt[from]);
        child[parent[from]].erase(from);
    }
    parent[from] = -1;

    child[to].insert(from);
    parent[from] = to;
    sumCnt(to, childCnt[from]);
    //printValue();
}


int cmd_find(char path[PATH_MAXLEN + 1]) { 
    string st = path;
    string tmp = "";
    int idx = 0;
    for(int i=1; i<st.size(); i++) {
        if(st[i] == '/') {
            for(auto iter : child[idx]) {
                if(names[iter] == tmp) {
                    idx = iter;
                    break;
                }
            }
            tmp = "";
            continue;
        }
        tmp+=st[i];
    }

    return childCnt[idx] - 1; 
}
