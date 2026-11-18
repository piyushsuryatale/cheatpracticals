// Q14. BST: 1. Insert new node  2. Mirror the tree (swap left/right at every node)  3. Search a value
#include <iostream>
using namespace std;
struct Node
{
 int data;
 Node* left;
 Node* right;
};
Node* insert(Node* root, int value)
{
 if(root == NULL)
 {
 Node* newNode = new Node;
 newNode->data = value;
 newNode->left = newNode->right = NULL;
 return newNode;
 }
 if(value < root->data)
 root->left = insert(root->left, value);
 else
 root->right = insert(root->right, value);
 return root;
}
void mirror(Node* root) // swap left and right pointers at every node
{
 if(root == NULL)
 return;
 Node* temp = root->left;
 root->left = root->right;
 root->right = temp;
 mirror(root->left);
 mirror(root->right);
}
bool search(Node* root, int key) // checks both subtrees, so it also works after mirroring
{
 if(root == NULL)
 return false;
 if(root->data == key)
 return true;
 return search(root->left, key) || search(root->right, key);
}
void inorder(Node* root)
{
 if(root != NULL)
 {
 inorder(root->left);
 cout << root->data << " ";
 inorder(root->right);
 }
}
int main()
{
 Node* root = NULL;
 int n, value, choice;
 cout << "Enter number of values: ";
 cin >> n;
 cout << "Enter values: ";
 for(int i = 0; i < n; i++)
 {
 cin >> value;
 root = insert(root, value);
 }
 do
 {
 cout << "\n1. Insert new node\n2. Mirror tree\n3. Search value\n4. Display (inorder)\n0. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 if(choice == 1)
 {
 cout << "Enter value: ";
 cin >> value;
 root = insert(root, value);
 }
 else if(choice == 2)
 mirror(root);
 else if(choice == 3)
 {
 cout << "Enter value: ";
 cin >> value;
 cout << (search(root, value) ? "Value found" : "Value not found") << endl;
 }
 else if(choice == 4)
 {
 inorder(root);
 cout << endl;
 }
 } while(choice != 0);
 return 0;
}
