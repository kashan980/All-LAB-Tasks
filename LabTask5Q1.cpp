#include <iostream>
using namespace std;
class Queue {
private:
 int front;
 int rear;
 int capacity;
 string* data;
public:
 Queue(int capacity = 100) : capacity(capacity), front(0), rear(0) {
 data = new string[capacity];
 }
 ~Queue() {
 delete[] data;
 }
 bool enqueue(const string& element) {
 if ((rear + 1) % capacity == front) {
 cout << "Error: Queue overflow!" << endl;
 return false;
 }
 data[rear] = element;
 rear = (rear + 1) % capacity;
 return true;
 }
 string dequeue() {
 if (front == rear) {
 cout << "Error: Queue underflow!" << endl;
 return "";
 }
 string element = data[front];
 front = (front + 1) % capacity;
 return element;
 }
 bool isEmpty() {
 return front == rear;
 }
 void display() {
 for (int i = front; i != rear; i = (i + 1) % capacity) {
 cout << data[i] << " ";
 }
 cout << endl;
 return;
 }
};
int main() {
 Queue q;
 q.enqueue("Apple");
 q.enqueue("Banana");
 q.enqueue("Cherry");
 q.display(); // Output: Apple Banana Cherry
 cout << "Dequeued: " << q.dequeue() << endl; // Output: Apple
 cout << "Dequeued: " << q.dequeue() << endl; // Output: Banana
 q.display(); // Output: Cherry
 return 0;
}
