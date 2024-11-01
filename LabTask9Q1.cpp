#include <iostream>
using namespace std;
struct Node {
 int data;
 Node *next;
};
class Queue {
 Node *front, *rear;
 int maxSize; // Maximum size of the queue
 int currentSize; // Current number of elements in the queue
public:
 Queue(int size) : maxSize(size), currentSize(0) {
 front = rear = NULL; // Initially empty
 }
 void Enqueue(int data) { // Insertion from rear
 if (currentSize >= maxSize) {
 cout << "Queue Overflow: Cannot add item, the queue is full." << endl;
 return;
 }
 Node *newnode = new Node;
 newnode->data = data;
 newnode->next = NULL;
 if (front == NULL) {
 front = rear = newnode; // Queue is empty
 } else {
 rear->next = newnode;
 rear = newnode; // Move rear to the new node
 }
 currentSize++; // Increment current size
 }
 void Dequeue() { // Deletion from front
 if (front == NULL) {
 cout << "Queue is Empty" << endl;
 return;
 }
 Node *temp = front;
 front = front->next;
 delete temp;
 currentSize--; // Decrement current size
 }
 int Count() { // Count elements in the queue
 return currentSize;
 }
 void Clear() { // Clear the entire queue
 while (front != NULL) {
 Dequeue(); // Dequeue all elements
 }
 rear = NULL; // Reset rear
 currentSize = 0; // Reset size
 }
 void Display() { // Display the queue
 Node *temp = front;
 while (temp != NULL) {
 cout << temp->data << "\t";
 temp = temp->next;
 }
 cout << endl;
 }
};
int main() {
 Queue Q1(3); // Create a queue with a maximum size of 3
 Q1.Enqueue(10);
 Q1.Enqueue(20);
 Q1.Enqueue(30);
 Q1.Enqueue(40); // This will trigger overflow
 cout << "Queue after Enqueue:" << endl;
 Q1.Display();
 cout << "Count: " << Q1.Count() << endl; // Count elements
 Q1.Dequeue();
 cout << "Queue after Dequeue:" << endl;
 Q1.Display();
 Q1.Clear(); // Clear the queue
 cout << "Queue after Clear:" << endl;
 Q1.Display();
 return 0;
}
