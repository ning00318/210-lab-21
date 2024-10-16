// COMSC-210 | Lab 21: Goat Herd Manager 3000 | Nina Tsao

#include <iostream>
#include <cstdlib>  // rand()
#include <ctime>    // time()
using namespace std;

const int MIN_LS = 5, MAX_LS = 20;

// a string array of 15 names
string names[] = {"Alice", "Bob", "Charlie", "David", "Emily", "Frank", "Grace",
    "Henry", "Isabella", "Jack", "Katherine", "Liam", "Mia", "Noah", "Olivia"};

// a string array of 15 names
string colors[] = {"red", "blue", "green", "yellow", "orange", "purple", "pink", 
    "brown", "gray", "black", "white", "cyan", "magenta", "gold", "silver"};

// Goat class
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
        cout << "\t" << name << " (" << color << ", " << age << ")" << endl;
    }
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;  // Goat rather than int
        Node* prev;
        Node* next;
        
        Node(Goat d, Node* p = nullptr, Node* n = nullptr) {    // Goat rather than int
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
    
    void push_back(Goat g) {    // Goat rather than int
        Node* newNode = new Node(g);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat g) {   // Goat rather than int
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
        if (!current) {
            cout << "List is empty" << endl;    // display the text if the list is empty
            return;
        }
        while (current) {
            current->data.print();
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) {
            cout << "List is empty" << endl;    // display the text if the list is empty
            return;
        }
        while (current) {
            current->data.print();
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
    srand(time(0));     // to randomize random numbers
    DoublyLinkedList list;
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;     // random number, range 5-20

    for (int i = 0; i < size; ++i)
        list.push_back(Goat());     // append a random number of Goat objects
    cout << "Forward: " << endl;
    list.print();

    cout << "Backward: " << endl;
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}