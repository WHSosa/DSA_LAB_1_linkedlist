// Lab 1: Singly Linked List for Username/Password storage

// Goal: Implement a simple credential store using a singly linked list

// Instructions:
// 1) Search for "TODO" and implement each function.
// 2) Build & run:   g++ -std=c++17 -O2 -Wall linked_lists.cpp -o lab && ./lab
// 3) Do not change function signatures

// NOTE: In the real world, NEVER store plaintext passwords.


#include <iostream>
#include <string>
using namespace std;

// -----------------------------
// Data Model
// -----------------------------
struct User {
    string username;
    string password; 
    User* next;
    
    User(string u, string p) {
        username = u;
        password = p;
        next = nullptr;
    }
};

// -----------------------------
// Core API — implement these
// -----------------------------

// Inserts a new (username, password) at the END of the list.
// If username already exists, do NOT insert a duplicate; return false.
// Otherwise insert and return true.
bool insertUser(User*& head, const string& username, const string& password) {
    // O(n) time complexity
    if (head == nullptr) {
        head = new User(username, password);
        return true;
    }
    User* current = head;
    while (current->next != nullptr) {
        if (current -> username == username) {
            return false;
        }
        current = current->next;
    }
    if (current -> username == username) return false;
    current -> next = new User(username, password);
   
    return true;
}

// Returns pointer to the node with matching username; otherwise nullptr.
User* findUser(User* head, const string& username) {
    // O(n) time complexity
    User* current = head;
    while (current !=nullptr) {
        if (current -> username == username) return current;
        current = current -> next;
    }
    
    return nullptr;
}

// Returns true if (username, password) matches an existing node; false otherwise.
bool authenticate(User* head, const string& username, const string& password) {
    // O(n) time complexity
    User* user = findUser(head, username);   
    return (user != nullptr && user -> password == password);
}

// Deletes the FIRST node (head) and updates head. No-op if list is empty.
// Return true if a node was deleted, false otherwise.
bool removeFront(User*& head) {
    // O(1) time complexity
    if (head == nullptr) return false;
    User* temp = head;
    head = head -> next;
    delete temp;
    return true;
}

// Deletes the node with matching username (first match only).
// Return true if a node was found & deleted; false if not found.
bool removeByUsername(User*& head, const string& username) {
    // O(n) time complexity
    if (head == nullptr) return false;
    if (head -> username == username) {
        return removeFront(head);
    }
    User* current = head;
    while (current -> next != nullptr) {
        if (current -> next -> username == username) {
            User* toDelete = current -> next;
            current -> next = toDelete -> next;
            delete toDelete;
            return true;
        }
        current = current -> next;
    }
    
    return false;
}

// Deletes ALL nodes and sets head=nullptr. 
void clearList(User*& head) {
    // O(n) time complexity
    while (head != nullptr) {
        removeFront(head);
    }
    
}

// Returns number of nodes.
size_t size(User* head) {
    // O(n) time complexity
    size_t count = 0;
    User* current = head;
    while (current != nullptr)
    {
        count++;
        current = current -> next;
    }
    
    return count;
}

// Prints usernames in order, separated by " -> " then " -> NULL".
// Example: alice -> bob -> charlie -> NULL
void printUsers(User* head) {
    // O(n) time complexity
    User* current = head;
    while (current !=nullptr) {
        cout << current -> username << " -> ";
        current = current -> next;
    }
    cout << "null" <<endl;
}

int main() {
  
    // Write code here to test your implementation
    
    return 0;
}