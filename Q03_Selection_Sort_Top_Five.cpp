// Q3. Store first year percentages in an array. Sort ascending using Selection Sort
// and display the top five scores.
#include <iostream>
using namespace std;
void selectionSort(float arr[], int n)
{
 for(int i = 0; i < n - 1; i++)
 {
 int minIndex = i;
 for(int j = i + 1; j < n; j++)
 {
 if(arr[j] < arr[minIndex])
 {
 minIndex = j;
 }
 }
 float temp = arr[i];
 arr[i] = arr[minIndex];
 arr[minIndex] = temp;
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
 selectionSort(arr, n);
 cout << "Sorted percentages (ascending): ";
 for(int i = 0; i < n; i++)
 {
 cout << arr[i] << " ";
 }
 cout << endl;
 displayTopFive(arr, n);
 return 0;
}
