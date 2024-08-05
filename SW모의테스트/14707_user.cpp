#include <iostream>
#include <vector>
#include <cstring>

typedef struct Node {
    Node* nodes[28];
    int cnt;

     Node() : cnt(0) {
        for (int i = 0; i < 28; ++i) {
            nodes[i] = nullptr;
        }
    }
} Node;

void deleteNodes(Node* node) {
    if (node == nullptr) return;

    for (int i = 0; i < 26; i++) {
        if (node->nodes[i] != nullptr) {
            deleteNodes(node->nodes[i]);
        }
    }
    delete node;
}

using namespace std;

Node* root;
int words;

void countNode(Node* node, char st[], int idx, bool isRemove);

void findCase(char st[], bool isRemove) {
    words = 0;
    char ch = st[0];
    if(ch == '?') {
        for(int i=0; i<26; i++) {
            Node * startNode = root->nodes[i];
            if(startNode != nullptr) countNode(startNode, st, 0, isRemove);
        }
    } else {
        Node * startNode = root->nodes[ch - 'a'];
        if(startNode != nullptr) countNode(startNode, st, 0, isRemove);
    }
}

void countNode(Node* node, char st[], int idx, bool isRemove) {
    if(node != nullptr ){
        char nextChar = st[idx+1];
        if(nextChar == '\0') {
            words += node->cnt;
            if(isRemove) node->cnt = 0;
        }
        else if(nextChar == '?') {
            for(int i=0; i<26; i++) {
                countNode(node->nodes[i], st, idx+1, isRemove);
            }
        } 
        else {
            countNode(node->nodes[nextChar - 'a'], st, idx+1, isRemove);
        }
    }
}

void init() {
    if(root != nullptr) deleteNodes(root);
    root = new Node();
	return;
}

int add(char str[]) {
    Node* current = root;
    
    for(int i=0; i<strlen(str); i++) {
        char ch = str[i];
        if(ch == '\0') break;
        int idx = ch - 'a';
        if(idx < 0 || idx >= 26) continue;
        if (current->nodes[idx] == nullptr) {
            current->nodes[idx] = new Node();
        }
        current = current->nodes[idx];
    }

    current->cnt = current->cnt + 1;

	return current->cnt;
}

int remove(char str[]) {
    findCase(str, true);
	return words;
}

int search(char str[]) {
    findCase(str, false);
	return words;
}