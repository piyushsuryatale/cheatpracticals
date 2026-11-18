// Q4. Store first year percentages in an array. Sort ascending using Bubble Sort
// and display the top five scores.
#include <iostream>
using namespace std;
void bubbleSort(float arr[], int n)
{
 for(int i = 0; i < n - 1; i++)
 {
 for(int j = 0; j < n - i - 1; j++)
 {
 if(arr[j] > arr[j + 1])
 {
 float temp = arr[j];
 arr[j] = arr[j + 1];
 arr[j + 1] = temp;
 }
 }
 }
}
void displayTopFive(float arr[], int n)
{
 cout << "Top five scores:" << endl;
 int count = 0;
 for(int i = n - 1; i >= 0 && count < 5; i--)
 {
 cout << arr[i] << endl;
 count++;
 }
}
int main()
{
 int n;
 cout << "Enter number of students: ";
 cin >> n;
 float arr[100];
 cout << "Enter first year percentages: ";
 for(int i = 0; i < n; i++)
 {
 cin >> arr[i];
 }
 bubbleSort(arr, n);
 cout << "Sorted percentages (ascending): ";
 for(int i = 0; i < n; i++)
 {
 cout << arr[i] << " ";
 }
 cout << endl;
 displayTopFive(arr, n);
 return 0;
}
