
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() {
        head = nullptr;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void displayList() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void displayFirstNode() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
        } else {
            cout << "First node: " << head->data << endl;
        }
    }
    void displayLastNode() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        cout << "Last node: " << temp->data << endl;
    }
    void displayNthNode(int n) {
        if (n <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < n) {
            temp = temp->next;
            count++;
        }
        if (temp != nullptr) {
            cout << "Nth node (" << n << "): " << temp->data << endl;
        } else {
            cout << "Position out of bounds!" << endl;
        }
    }
    void displayCentreNode() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Centre node: " << slow->data << endl;
    }
};
int main() {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.displayList();
    list.displayFirstNode();
    list.displayLastNode();
    list.displayNthNode(3);
    list.displayCentreNode();
    return 0;
}
