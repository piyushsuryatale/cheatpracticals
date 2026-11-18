// Q13. BST: 1. Insert new node  2. Number of nodes in longest path from root  3. Minimum value
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
int longestPath(Node* root) // number of nodes in longest path from root
{
 if(root == NULL)
 return 0;
 int l = longestPath(root->left);
 int r = longestPath(root->right);
 return (l > r ? l : r) + 1;
}
int findMin(Node* root)
{
 while(root->left != NULL)
 root = root->left;
 return root->data;
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
 cout << "\n1. Insert new node\n2. Nodes in longest path\n3. Minimum value\n0. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 if(choice == 1)
 {
 cout << "Enter value: ";
 cin >> value;
 root = insert(root, value);
 }
 else if(choice == 2)
 cout << "Nodes in longest path: " << longestPath(root) << endl;
 else if(choice == 3 && root != NULL)
 cout << "Minimum value: " << findMin(root) << endl;
 } while(choice != 0);
 return 0;
}
