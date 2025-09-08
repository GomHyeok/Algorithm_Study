#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// head를 참조로 전달
void push(Node*& head, int data) {
    Node* node = new Node(data);
    node->next = head;
    head = node;
}

void insert(Node* prev, int data) {
    if(prev == NULL) {
        cout<<"Null Pointer Exception"<<endl;
        return;
    }

    Node* node = new Node(data);

    node->next = prev->next;
    prev->next = node;
}

// tail을 참조로 전달
void append(Node*& tail, int data) {
    if(tail == NULL) {
        cout<<"Null Pointer Exception"<<endl;
        return;
    }

    Node* node = new Node(data);
    tail->next = node;
    tail = node;
}

// head를 참조로 전달
int erase(Node*& head) {
    if(head == NULL) {
        cout << "List is empty" << endl;
        return -1; // Or throw an exception
    }
    Node* front = head;
    int data = front->data;
    head = front->next;
    delete front;

    return data;
}

int deleteFrom(Node* prev) {
    if (prev == nullptr || prev->next == nullptr) {
        cout << "Invalid previous node or end of list" << endl;
        return -1; // Or throw an exception
    }
    Node* node = prev->next;
    prev->next = node->next;
    int data = node->data;
    delete node;

    return data;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // push로 앞에 삽입
    push(head, 10);
    tail = head; // head가 갱신되었으므로 tail도 갱신
    push(head, 20);
    push(head, 30);
    // 이 시점에서 tail은 10을 가리키고 있어야 함.
    // 하지만 push는 head만 갱신하므로 tail을 다시 찾아야 함.
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    tail = current;

    cout << "After push operations: ";
    printList(head);

    // append로 뒤에 삽입
    append(tail, 40);
    append(tail, 50);
    cout << "After append operations: ";
    printList(head);

    // insert (head->next 뒤에 삽입)
    insert(head->next, 25);
    cout << "After insert: ";
    printList(head);

    // erase (맨 앞 삭제)
    cout << "Erased front: " << erase(head) << endl;
    cout << "After erase front: ";
    printList(head);

    // deleteFrom (head 뒤 노드 삭제)
    cout << "Deleted from head: " << deleteFrom(head) << endl;
    cout << "After deleteFrom: ";
    printList(head);

    // 메모리 해제
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}