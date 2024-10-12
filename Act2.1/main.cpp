/*
By: Gilberto Malagamba Montejo
Date: 10/11/2024
Description: This program implements a linked list with the following operations:
Create a node, read the list, update a node, delete a node
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class linked_list {
    private:
        Node* head;
        Node* tail;
    public:
        linked_list() {
            head = NULL;
            tail = NULL;
        }
        // Complexity: O(1)
        void createNode(int n) {
            Node* tmp = new Node;
            tmp->data = n;
            tmp->next = NULL;
            if (head == NULL) {
                head = tmp;
                tail = tmp;
            } else {
                tail->next = tmp;
                tail = tail->next;
            }
        }
        // Complexity: O(n)
        void readList() {
            Node* tmp = head;
            while (tmp != NULL) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
        // Complexity: O(n)
        void updateNode(int pos, int n) {
            Node* tmp = head;
            for (int i = 0; i < pos; i++) {
                tmp = tmp->next;
            }
            tmp->data = n;
        }
        // Complexity: O(n)
        void deleteNode(int pos) {
            Node* tmp = head;
            if (pos == 0) {
                head = head->next;
                delete tmp;
            } else {
                for (int i = 0; i < pos - 1; i++) {
                    tmp = tmp->next;
                }
                Node* tmp2 = tmp->next;
                tmp->next = tmp2->next;
                delete tmp2;
            }
        }
};

int main() {
    linked_list list;
    list.createNode(1);
    list.createNode(2);
    list.createNode(3);
    list.createNode(4);
    list.createNode(5);
    list.readList();
    list.updateNode(2, 10);
    list.readList();
    list.deleteNode(2);
    list.readList();
    return 0;
}