// Q2. Store roll numbers of students who attended a training program in sorted order.
// Search whether a student attended using binary search.
#include <iostream>
using namespace std;
void binarySearch(int arr[], int n, int key)
{
 int low = 0, high = n - 1;
 while(low <= high)
 {
 int mid = (low + high) / 2;
 if(arr[mid] == key)
 {
 cout << "Student attended the training program";
 return;
 }
 else if(arr[mid] < key)
 {
 low = mid + 1;
 }
 else
 {
 high = mid - 1;
 }
 }
 cout << "Student did not attend the training program";
}
int main()
{
 int n, key;
 cout << "Enter number of students: ";
 cin >> n;
 int arr[100];
 cout << "Enter roll numbers in ascending order: ";
 for(int i = 0; i < n; i++)
 {
 cin >> arr[i];
 }
 cout << "Enter roll number to search: ";
 cin >> key;
 binarySearch(arr, n, key);
 return 0;
}
