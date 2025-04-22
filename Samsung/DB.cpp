#include<bits/stdc++.h>
using namespace std;

#define INF 2e9 + 5
#define MOD 998244353

int query_count;

// 현재 테이블에 저장된 데이터의 개수를 저장합니다.
int entry_count;
// name을 key로, 해당 데이터의 index를 value로 저장합니다.
map<string, int> name_to_index;
// 사용된 value들을 저장하는 set입니다.
set<int> used_values;
// index를 통해 name을 저장하는 배열입니다.
string names[100005];
// index를 통해 value를 저장하는 배열입니다.
int values[100005];

// 세그먼트 트리의 노드를 정의합니다.
struct SegmentTreeNode {
    int left = 0, right = 0, index = 0;
    int count = 0; // 해당 구간에 존재하는 데이터의 개수
    long long sum = 0; // 해당 구간에 존재하는 데이터의 value 합
}; 

// 세그먼트 트리를 저장하는 벡터입니다.
vector<SegmentTreeNode> segment_tree;

// 세그먼트 트리의 업데이트를 수행하는 함수입니다.
void update(int node_id, int left, int right, int position, int index, int count, int sum) {
    // 업데이트할 위치가 현재 구간에 포함되지 않으면 종료합니다.
    if(right < position || position < left) return;
    // 리프 노드에 도달하면 값을 업데이트합니다.
    if(left == right) {
        segment_tree[node_id].index = index;
        segment_tree[node_id].count = count;
        segment_tree[node_id].sum = sum;
        return;
    }
    int mid = (left + right) / 2;
    // 왼쪽 자식 노드가 없으면 새로 생성합니다.
    if(position <= mid) {
        if(!segment_tree[node_id].left) {
            segment_tree[node_id].left = segment_tree.size();
            SegmentTreeNode new_node;
            segment_tree.push_back(new_node);
        }
        update(segment_tree[node_id].left, left, mid, position, index, count, sum);
    }
    // 오른쪽 자식 노드가 없으면 새로 생성합니다.
    else {
        if(!segment_tree[node_id].right) {
            segment_tree[node_id].right = segment_tree.size();
            SegmentTreeNode new_node;
            segment_tree.push_back(new_node);
        }
        update(segment_tree[node_id].right, mid + 1, right, position, index, count, sum);
    }

    // 현재 노드의 값을 자식 노드의 값으로 갱신합니다.
    segment_tree[node_id].count = segment_tree[segment_tree[node_id].left].count + segment_tree[segment_tree[node_id].right].count;
    segment_tree[node_id].sum = segment_tree[segment_tree[node_id].left].sum + segment_tree[segment_tree[node_id].right].sum;
    return;
}

// 구간 합을 구하는 쿼리 함수입니다.
long long query_sum(int node_id, int left, int right, int query_left, int query_right) {
    // 구간이 겹치지 않으면 0을 반환합니다.
    if(query_right < left || right < query_left) return 0;
    // 구간이 완전히 포함되면 해당 노드의 합을 반환합니다.
    if(query_left <= left && right <= query_right) return segment_tree[node_id].sum;
    int mid = (left + right) / 2;
    long long result = 0;
    // 왼쪽 자식 노드가 존재하면 왼쪽 구간의 합을 구합니다.
    if(segment_tree[node_id].left) {
        result += query_sum(segment_tree[node_id].left, left, mid, query_left, query_right);
    }
    // 오른쪽 자식 노드가 존재하면 오른쪽 구간의 합을 구합니다.
    if(segment_tree[node_id].right) {
        result += query_sum(segment_tree[node_id].right, mid + 1, right, query_left, query_right);
    }
    return result;
}

// k번째로 작은 값을 찾는 쿼리 함수입니다.
int query_rank(int node_id, int left, int right, int rank) {
    // 리프 노드에 도달하면 해당 노드의 index를 반환합니다.
    if(left == right) return segment_tree[node_id].index;
    int mid = (left + right) / 2;
    // 왼쪽 자식 노드가 존재하고, 왼쪽 구간의 데이터 개수가 rank 이상이면 왼쪽 구간에서 찾습니다.
    if(segment_tree[node_id].left) {
        if(segment_tree[segment_tree[node_id].left].count >= rank) return query_rank(segment_tree[node_id].left, left, mid, rank);
        // 그렇지 않으면 오른쪽 구간에서 rank - 왼쪽 구간의 데이터 개수 번째로 작은 값을 찾습니다.
        return query_rank(segment_tree[node_id].right, mid + 1, right, rank - segment_tree[segment_tree[node_id].left].count);
    }
    // 왼쪽 자식 노드가 없으면 오른쪽 구간에서 찾습니다.
    return query_rank(segment_tree[node_id].right, mid + 1, right, rank);
}

// init 쿼리를 처리하는 함수입니다.
void handle_init() {
    segment_tree.clear();
    SegmentTreeNode root;
    segment_tree.push_back(root);
    SegmentTreeNode dummy;
    segment_tree.push_back(dummy);

    entry_count = 0;
    name_to_index.clear();
    used_values.clear();
}

// insert 쿼리를 처리하는 함수입니다.
void handle_insert(string name, int value) {
    // 이미 존재하는 name이나 value가 있으면 0을 출력합니다.
    if(name_to_index.find(name) != name_to_index.end() || used_values.find(value) != used_values.end()) {
        cout << "0\n";
        return;
    }

    // 새로운 데이터를 삽입합니다.
    name_to_index[name] = ++entry_count;
    names[entry_count] = name;
    used_values.insert(value);
    values[entry_count] = value;

    // 세그먼트 트리를 업데이트합니다.
    update(1, 1, 1e9, value, entry_count, 1, value);
    cout << "1\n";
}

// delete 쿼리를 처리하는 함수입니다.
void handle_delete(string name) {
    // 해당 name이 존재하지 않으면 0을 출력합니다.
    if(name_to_index.find(name) == name_to_index.end()) {
        cout << "0\n";
        return;
    }

    // 해당 데이터를 삭제합니다.
    int index = name_to_index[name];
    name_to_index.erase(name);
    used_values.erase(values[index]);

    // 세그먼트 트리를 업데이트합니다.
    update(1, 1, 1e9, values[index], index, 0, 0);
    cout << values[index] << "\n";
}

// rank 쿼리를 처리하는 함수입니다.
void handle_rank(int k) {
    // 데이터 개수가 k보다 작으면 None을 출력합니다.
    if(segment_tree[1].count < k) {
        cout << "None\n";
        return;
    }
    // k번째로 작은 값을 찾습니다.
    int index = query_rank(1, 1, 1e9, k);
    cout << names[index] << "\n";
}

// sum 쿼리를 처리하는 함수입니다.
void handle_sum(int k) {
    // k 이하의 값들의 합을 구합니다.
    long long sum_value = query_sum(1, 1, 1e9, 1, k);
    cout << sum_value << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> query_count;
    while(query_count--) {
        string query_type;
        cin >> query_type;
        if(query_type == "init") {
            handle_init();
        }
        else if(query_type == "insert") {
            string name;
            int value;
            cin >> name >> value;
            handle_insert(name, value);
        }
        else if(query_type == "delete") {
            string name;
            cin >> name;
            handle_delete(name);
        }
        else if(query_type == "rank") {
            int k;
            cin >> k;
            handle_rank(k);
        }
        else if(query_type == "sum") {
            int k;
            cin >> k;
            handle_sum(k);
        }
    }    
}
