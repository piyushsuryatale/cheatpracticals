// Q8. Pinnacle Club using a singly linked list (first node = president, last = secretary).
// a) Add members/president/secretary  b) Count members  c) Display members
#include <iostream>
#include <string>
using namespace std;
struct Node
{
 int prn;
 string name;
 Node* next;
};
Node* head = NULL;
bool hasSecretary = false;
Node* createNode(int prn, string name)
{
 Node* newNode = new Node;
 newNode->prn = prn;
 newNode->name = name;
 newNode->next = NULL;
 return newNode;
}
void addPresident(int prn, string name)
{
 if(head != NULL)
 {
 cout << "President already exists\n";
 return;
 }
 head = createNode(prn, name);
}
void addSecretary(int prn, string name)
{
 if(head == NULL || hasSecretary)
 {
 cout << "Add president first / secretary already exists\n";
 return;
 }
 Node* temp = head;
 while(temp->next != NULL)
 temp = temp->next;
 temp->next = createNode(prn, name);
 hasSecretary = true;
}
void addMember(int prn, string name)
{
 if(head == NULL)
 {
 cout << "Add president first\n";
 return;
 }
 Node* newNode = createNode(prn, name);
 Node* temp = head;
 // go to the last node, or stop before the secretary
 while(temp->next != NULL && !(hasSecretary && temp->next->next == NULL))
 temp = temp->next;
 newNode->next = temp->next;
 temp->next = newNode;
}
int countMembers()
{
 int count = 0;
 for(Node* temp = head; temp != NULL; temp = temp->next)
 count++;
 return count;
}
void displayMembers()
{
 for(Node* temp = head; temp != NULL; temp = temp->next)
 {
 cout << temp->prn << " " << temp->name;
 if(temp == head)
 cout << " (President)";
 else if(temp->next == NULL && hasSecretary)
 cout << " (Secretary)";
 cout << endl;
 }
}
int main()
{
 int choice, prn;
 string name;
 do
 {
 cout << "\n1. Add president\n2. Add secretary\n3. Add member\n";
 cout << "4. Total members\n5. Display members\n0. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 if(choice >= 1 && choice <= 3)
 {
 cout << "Enter PRN and name: ";
 cin >> prn >> name;
 }
 if(choice == 1) addPresident(prn, name);
 else if(choice == 2) addSecretary(prn, name);
 else if(choice == 3) addMember(prn, name);
 else if(choice == 4) cout << "Total members: " << countMembers() << endl;
 else if(choice == 5) displayMembers();
 } while(choice != 0);
 return 0;
}
