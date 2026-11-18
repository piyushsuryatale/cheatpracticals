// Q1. Store roll numbers of students who attended a training program (random order).
// Search whether a student attended using linear search.
#include <iostream>
using namespace std;
void linearSearch(int arr[], int n, int key)
{
 for(int i = 0; i < n; i++)
 {
 if(arr[i] == key)
 {
 cout << "Student attended the training program";
 return;
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
 cout << "Enter roll numbers: ";
 for(int i = 0; i < n; i++)
 {
 cin >> arr[i];
 }
 cout << "Enter roll number to search: ";
 cin >> key;
 linearSearch(arr, n, key);
 return 0;
}
