#include <iostream>
#include <string>
using namespace std;
// Node class to represent a node of the linked list.
class Node {
public:
 string name;
 int sapp_id;
 Node* next;
 // Default constructor
 Node() {
 next = NULL;
 }
 // Parameterised Constructor
 Node(string name, int sapp_id) {
 this->name = name;
 this->sapp_id = sapp_id;
 this->next = NULL;
 }
};
// Linked list class.
class LinkedList {
 Node* head;
public:
 // Default constructor
 LinkedList() { head = NULL; }
 // Insert a node at the end of the linked list.
 void insertNode(string name, int sapp_id);
 // Print all the nodes in the linked list.
 void printList();
 // Delete the node at a given position
 void deleteNode(int position);
};
// Insert a new node.
void LinkedList::insertNode(string name, int sapp_id) {
 Node* newNode = new Node(name, sapp_id);
 if (head == NULL) {
 head = newNode;
 return;
 }
 Node* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;
}
// Print all the nodes of the linked list.
void LinkedList::printList() {
 Node* temp = head;
 if (head == NULL) {
 cout << "List is empty" << endl;
 return;
 }
 while (temp != NULL) {
 cout << "Name: " << temp->name << ", SAP ID: " << temp->sapp_id << endl;
 temp = temp->next;
 }
}
// Delete the node at a given position
void LinkedList::deleteNode(int position) {
 Node* temp1 = head, *temp2 = NULL;
 int ListLen = 0;
 if (head == NULL) {
 cout << "LIST IS EMPTY deletion not performed" << endl;
 return;
 }
 Node* temp = head;
 while (temp != NULL) {
 temp = temp->next;
 ListLen++;
 }
 if (ListLen < position) {
 cout << "Index is out of range" << endl;
 return;
 }
 temp1 = head;
 if (position == 1) {
 head = head->next;
 delete temp1;
 return;
 }
 while (position-- > 1) {
 temp2 = temp1;
 temp1 = temp1->next;
 }
 temp2->next = temp1->next;
 delete temp1;
}
// Driver Code
int main() {
 LinkedList list;
 int n;
 cout << "Enter the number of students: ";
 cin >> n;
 for (int i = 0; i < n; i++) {
 string name;
 int sapp_id;
 cout << "Enter name and SAP ID of student " << i + 1 << ": ";
 cin >> name >> sapp_id;
 list.insertNode(name, sapp_id);
 }
 cout << "Initial list:" << endl;
 list.printList();
 list.deleteNode(2);
 list.deleteNode(4); // 5th student
 cout << "List after deletion of 2nd and 5th students:" << endl;
 list.printList();
 return 0;
}
