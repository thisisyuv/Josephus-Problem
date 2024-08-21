#include <iostream>
using namespace std;

class Node {
public:
    int sno;
    Node *nextnode;
    Node(int no) {
        sno = no;
        nextnode = NULL;
    } 
};

class Link {
public:
    Node *head = NULL;
    Node *tail = NULL;
    int len = 0;

    void add(int a) {
        Node *newnode = new Node(a);
        len=len+1;
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            newnode->nextnode = head; // Circular link
        } else {
            tail->nextnode = newnode;
            tail = newnode;
            newnode->nextnode = head; // Maintain circular link
        }
    }

    void printcl() {
        Node *temp = head;
        if (head != NULL) {
            do {
                cout << temp->sno << ' ';
                temp = temp->nextnode;
            } while (temp != head);
        }
        cout << endl;
    }

    void kill(Node *killer) {
        Node *dead = killer->nextnode;
        killer->nextnode = dead->nextnode;
        cout << dead->sno << " is Killed" << endl;
        head=killer->nextnode;
        len=len-1;
        delete dead;
    }

    ~Link() {
        if (head != NULL) {
            Node *current = head;
            do {
                Node *next = current->nextnode;
                delete current;
                current = next;
            } while (current != head);
        }
    }
};

int main() {
    cout << "Enter the Number of Soldiers: ";
    int n;
    cin >> n;
    Link *l1 = new Link();
    for (int i = 1; i <= n; i++) {
        l1->add(i);
    }
    l1->printcl();
    while(l1->len!=1){
        l1->kill(l1->head);
    }
    l1->printcl();

    delete l1; // Clean up allocated memory

    return 0;
}
