// Q12. Pizza parlor job queue (max M orders, first-come first-served) using a circular queue.
#include <iostream>
using namespace std;
int queueArr[100];
int front = 0, count = 0, M;
void addJob(int job)
{
 if(count == M)
 {
 cout << "Queue is full\n";
 return;
 }
 queueArr[(front + count) % M] = job;
 count++;
}
void deleteJob()
{
 if(count == 0)
 {
 cout << "Queue is empty\n";
 return;
 }
 cout << "Job served: " << queueArr[front] << endl;
 front = (front + 1) % M;
 count--;
}
void displayJobs()
{
 for(int i = 0; i < count; i++)
 cout << queueArr[(front + i) % M] << " ";
 cout << endl;
}
int main()
{
 int choice, job;
 cout << "Enter maximum number of orders (M <= 100): ";
 cin >> M;
 do
 {
 cout << "\n1. Add job\n2. Delete job\n3. Display jobs\n0. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 if(choice == 1)
 {
 cout << "Enter job (order) number: ";
 cin >> job;
 addJob(job);
 }
 else if(choice == 2)
 deleteJob();
 else if(choice == 3)
 displayJobs();
 } while(choice != 0);
 return 0;
}
