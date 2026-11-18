// Q9. Pinnacle Club using a singly linked list.
// a) Delete members/president/secretary  b) Display members  c) Concatenate two division lists
#include <iostream>
#include <string>
using namespace std;
struct Node
{
 int prn;
 string name;
 Node* next;
};
Node* head1 = NULL; // Division A
Node* head2 = NULL; // Division B
void insertAtEnd(Node*& head, int prn, string name)
{
 Node* newNode = new Node;
 newNode->prn = prn;
 newNode->name = name;
 newNode->next = NULL;
 if(head == NULL)
 {
 head = newNode;
 return;
 }
 Node* temp = head;
 while(temp->next != NULL)
 temp = temp->next;
 temp->next = newNode;
}
void deleteMember(Node*& head, int prn) // president, member or secretary
{
 Node* temp = head;
 Node* prev = NULL;
 while(temp != NULL && temp->prn != prn)
 {
 prev = temp;
 temp = temp->next;
 }
 if(temp == NULL)
 {
 cout << "Member not found\n";
 return;
 }
 if(prev == NULL)
 head = temp->next;
 else
 prev->next = temp->next;
 delete temp;
 cout << "Member deleted\n";
}
void display(Node* head)
{
 for(Node* temp = head; temp != NULL; temp = temp->next)
 {
 cout << temp->prn << " " << temp->name;
 if(temp == head)
 cout << " (President)";
 else if(temp->next == NULL)
 cout << " (Secretary)";
 cout << endl;
 }
}
void concatenate(Node*& h1, Node*& h2)
{
 if(h1 == NULL)
 {
 h1 = h2;
 }
 else
 {
 Node* temp = h1;
 while(temp->next != NULL)
 temp = temp->next;
 temp->next = h2;
 }
 h2 = NULL;
}
int main()
{
 int choice, division = 1, prn; // division initialised to avoid reading an uninitialised value
 string name;
 do
 {
 cout << "\n1. Add member (first = president, last = secretary)\n2. Delete member\n";
 cout << "3. Display members\n4. Concatenate Division B to Division A\n0. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 if(choice >= 1 && choice <= 3)
 {
 cout << "Enter division (1 = A, 2 = B): ";
 cin >> division;
 }
 Node*& list = (division == 1) ? head1 : head2;
 if(choice == 1)
 {
 cout << "Enter PRN and name: ";
 cin >> prn >> name;
 insertAtEnd(list, prn, name);
 }
 else if(choice == 2)
 {
 cout << "Enter PRN to delete: ";
 cin >> prn;
 deleteMember(list, prn);
 }
 else if(choice == 3)
 display(list);
 else if(choice == 4)
 concatenate(head1, head2);
 } while(choice != 0);
 return 0;
}
