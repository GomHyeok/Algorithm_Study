#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    private :
        Node* head;
    public :
        LinkedList() {
            this->head = nullptr;
        }

        void addNode(int data) {
            Node* node = new Node();
            node->data = data;
            node->next = nullptr;
            if(head == nullptr) {
                head = node;
                return;
            }

            node->next = head;
            head = node;
        }

        void append(int data) {
            Node* node = new Node();
            node -> data = data;
            node -> next = nullptr;
            Node* tail = head;

            while(tail->next != nullptr) {tail = tail->next;}

            tail->next = node;
        }

        int pop() {
            if(head == nullptr) {
                cout<<"Null";
                return -1;
            }

            Node* node = head;
            int data = node->data;

            head = node->next;

            delete node;

            return data;
        }

        void printList() {
            Node* curr = head;
            while (curr != nullptr) {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL" << endl;
        }
};

int main() {
    LinkedList list;

    // addNode 테스트 (앞에 삽입)
    list.addNode(10);
    list.addNode(20);
    list.addNode(30);
    cout << "After addNode (push front): ";
    list.printList();   // 30 -> 20 -> 10 -> NULL

    // append 테스트 (뒤에 삽입)
    list.append(40);
    list.append(50);
    cout << "After append (push back): ";
    list.printList();   // 30 -> 20 -> 10 -> 40 -> 50 -> NULL

    // pop 테스트
    cout << "Pop: " << list.pop() << endl;  // 30 삭제
    cout << "After pop: ";
    list.printList();   // 20 -> 10 -> 40 -> 50 -> NULL

    // pop 여러 번
    list.pop();
    list.pop();
    cout << "After multiple pops: ";
    list.printList();   // 40 -> 50 -> NULL

    // 빈 리스트 pop
    list.pop();
    list.pop();
    cout << "After clearing list: ";
    list.printList();   // NULL
    list.pop();         // "List is empty" 출력

    return 0;
}