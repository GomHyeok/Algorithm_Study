#include <iostream>
#include <vector>
#include <cstring>

typedef struct Node {
    Node* nodes[26];
    int cnt;
} Node;

using namespace std;

Node* root;
int words;

void countNode(Node* node, string st, int idx, bool isRemove);

void findCase(string st, bool isRemove) {
    words = 0;
    char ch = st[0];
    if(ch == '?') {
        for(int i=0; i<26; i++) {
            if(root->nodes[i] != NULL) countNode(root->nodes[i], st, 0, isRemove);
        }
    } else {
        countNode(root->nodes[ch-'a'], st, 0, isRemove);
    }
}

void countNode(Node* node, string st, int idx, bool isRemove) {
    if(node != NULL ){
        if(idx >= st.size() - 1) {
            words += node->cnt;
            if(isRemove) node->cnt = 0;
            return;
        }

        char ch = st[idx + 1];
        if(ch == '?') {
            for(int i=0; i<26; i++) {
                if(node->nodes[i] != NULL) countNode(node->nodes[i], st, idx+1, isRemove);
            }
        } else {
            countNode(node->nodes[ch-'a'], st, idx+1, isRemove);
        }
    }
}

void init() {
    root = new Node();
	return;
}

int add(char str[]) {
    string st = str;

    Node* current = root;

    for(int i=0; i<st.size(); i++) {
        int idx = st[i] - 'a';
        if(current->nodes[idx] == NULL) current->nodes[idx] = new Node();
        current = current->nodes[idx];
    }

    current->cnt++;

	return current->cnt;
}

int remove(char str[]) {
    string st = str;
    findCase(st, true);
	return words;
}

int search(char str[]) {
    string st = str;
    findCase(st, false);
	return words;
}