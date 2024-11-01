.#include <iostream>
using namespace std;
int binarySearchFirstOccurrence(int arr[], int target, int low, int high) {
 while (low <= high) {
 int mid = (low + high) / 2;
 cout << "Active items: ";
 for (int i = low; i <= mid; i++) {
 cout << arr[i] << " ";
 }
 cout << endl;
 if (arr[mid] == target) {
 // Check if it is the first occurrence
 if (mid == 0 || arr[mid - 1] != target) {
 return mid;
 } else {
 high = mid - 1;
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
 int result = binarySearchFirstOccurrence(arr, target, 0, n - 1);
 if (result != -1) {
 cout << "First occurrence of target value found at index " << result << std::endl;
 } else {
 cout << "Target value not found in the array" << endl;
 }
 delete[] arr;
 return 0;
}
