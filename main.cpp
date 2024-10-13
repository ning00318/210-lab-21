#include <iostream>
#include <cstdlib>  // rand()
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
string names[] = {"Alice", "Bob", "Charlie", "David", "Emily", "Frank", "Grace",
    "Henry", "Isabella", "Jack", "Katherine", "Liam", "Mia", "Noah", "Olivia"};
string colors[] = {"red", "blue", "green", "yellow", "orange", "purple", "pink", 
    "brown", "gray", "black", "white", "cyan", "magenta", "gold", "silver"};

class Goat {
private:
    int age;
    string name;
    string color;
    
    // default constructor
    Goat() {
        age = rand() % (20-1+1) + 1;            // randomly assign, 1-20
        name = names[rand() % (14-0+1) + 0];    // randomly selected from the 15-element names[] array
        color = colors[rand() % (14-0+1) + 0];  // randomly selected from the 15-element colors[] array
    }

    // parameter constructor
    Goat(int a, string n, string c) {       // 3-element parameter setup
        age = a;
        name = n;
        color = c;
    }
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        
        Node(Goat d, Node* p = nullptr, Node* n = nullptr) {
            data = d;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }
    
    void push_back(Goat) {
        Node* newNode = new Node(value);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat) {
        Node* newNode = new Node(value);
        if (!head) // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(int value, int position) {
    if (position < 0) {
        cout << "Position must be >= 0." << endl;
        return;
    }

    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < position && temp; ++i)
        temp = temp->next;
    if (!temp) {
        cout << "Position exceeds list size. Node not inserted.\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    else
        tail = newNode; // Inserting at the end
    temp->next = newNode;
    }
    void delete_node(int value) {
        if (!head) return; // Empty list
            Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }
    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}