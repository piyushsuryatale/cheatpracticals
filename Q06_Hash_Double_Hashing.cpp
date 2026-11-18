// Q6. Telephone book of N clients using a hash table with double hashing.
#include <iostream>
#include <string>
using namespace std;
const int SIZE = 11;
const int R = 7; // prime smaller than SIZE
string names[SIZE];
long long phones[SIZE];
int getKey(string name)
{
 int sum = 0;
 for(int i = 0; i < (int)name.length(); i++)
 sum += name[i];
 return sum;
}
int position(int key, int i)
{
 int h1 = key % SIZE;
 int h2 = R - (key % R);
 return (h1 + i * h2) % SIZE; // double hashing
}
void insertClient(string name, long long phone)
{
 int key = getKey(name);
 for(int i = 0; i < SIZE; i++)
 {
 int pos = position(key, i);
 if(names[pos] == "")
 {
 names[pos] = name;
 phones[pos] = phone;
 return;
 }
 }
 cout << "Hash table is full\n";
}
void searchClient(string name)
{
 int key = getKey(name);
 for(int i = 0; i < SIZE; i++)
 {
 int pos = position(key, i);
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
