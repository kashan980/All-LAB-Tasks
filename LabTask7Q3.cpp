#include <iostream>
using namespace std;
int binarySearchLastOccurrence(int arr[], int target, int low, int high) {
 while (low <= high) {
 int mid = (low + high) / 2;
 cout << "Active items: ";
 for (int i = low; i <= mid; i++) {
 cout << arr[i] << " ";
 }
 cout << endl;
 if (arr[mid] == target) {
 // Check if it is the last occurrence
 if (mid == high || arr[mid + 1] != target) {
 return mid;
 } else {
 low = mid + 1; // Continue searching in the right half
 }
 } else if (arr[mid] < target) {
 low = mid + 1;
 } else {
 high = mid - 1;
 }
 }
 return -1;
}
int main() {
 int n;
 cout << "Enter the number of elements in the array: ";
 cin >> n;
 int* arr = new int[n];
 cout << "Enter the elements of the array in sorted order: ";
 for (int i = 0; i < n; i++) {
 cin >> arr[i];
 }
 int target;
 cout << "Enter the target value: ";
 cin >> target;
 int result = binarySearchLastOccurrence(arr, target, 0, n - 1);
 if (result != -1) {
 cout << "Last occurrence of target value found at index " << result << endl;
 } else {
 cout << "Target value not found in the array" << endl;
 }
 delete[] arr;
 return 0;
}
