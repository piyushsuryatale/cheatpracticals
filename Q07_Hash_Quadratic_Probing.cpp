// Q7. Telephone book of N clients using a hash table with quadratic probing.
#include <iostream>
#include <string>
using namespace std;
const int SIZE = 11;
string names[SIZE];
long long phones[SIZE];
int hashFunction(string name)
{
 int sum = 0;
 for(int i = 0; i < (int)name.length(); i++)
 sum += name[i];
 return sum % SIZE;
}
void insertClient(string name, long long phone)
{
 int index = hashFunction(name);
 for(int i = 0; i < SIZE; i++)
 {
 int pos = (index + i * i) % SIZE; // quadratic probing
 if(names[pos] == "")
 {
 names[pos] = name;
 phones[pos] = phone;
 return;
 }
 }
 cout << "Could not insert client\n";
}
void searchClient(string name)
{
 int index = hashFunction(name);
 for(int i = 0; i < SIZE; i++)
 {
 int pos = (index + i * i) % SIZE;
 if(names[pos] == "")
 break;
 if(names[pos] == name)
 {
 cout << "Telephone number: " << phones[pos];
 return;
 }
 }
 cout << "Client not found";
}
int main()
{
 int n;
 string name;
 long long phone;
 cout << "Enter number of clients: ";
 cin >> n;
 for(int i = 0; i < n; i++)
 {
 cout << "Enter name and telephone number: ";
 cin >> name >> phone;
 insertClient(name, phone);
 }
 cout << "Enter name to search: ";
 cin >> name;
 searchClient(name);
 return 0;
}
