#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()
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

public:
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

    void print() {
        cout << "\t" << age << "\t" << name << "\t" << color;
        cout << endl;
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
    
    void push_back(Goat g) {
        Node* newNode = new Node(g);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat g) {
        Node* newNode = new Node(g);
        if (!head) // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
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
    srand(time(0));
    
    DoublyLinkedList list;
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(Goat());
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    // cout << "Deleting list, then trying to print.\n";
    // list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}