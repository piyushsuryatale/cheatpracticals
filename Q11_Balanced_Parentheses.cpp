// Q11. Check whether an expression is well parenthesized using a stack.
#include <iostream>
#include <string>
using namespace std;
char stackArr[100];
int top = -1;
void push(char ch)
{
 stackArr[++top] = ch;
}
char pop()
{
 return stackArr[top--];
}
bool isEmpty()
{
 return top == -1;
}
bool isWellParenthesized(string exp)
{
 for(int i = 0; i < (int)exp.length(); i++)
 {
 char ch = exp[i];
 if(ch == '(' || ch == '{' || ch == '[')
 {
 push(ch);
 }
 else if(ch == ')' || ch == '}' || ch == ']')
 {
 if(isEmpty())
 {
 return false;
 }
 char open = pop();
 if((ch == ')' && open != '(') ||
 (ch == '}' && open != '{') ||
 (ch == ']' && open != '['))
 {
 return false;
 }
 }
 }
 return isEmpty();
}
int main()
{
 string exp;
 cout << "Enter an expression: ";
 getline(cin, exp);
 if(isWellParenthesized(exp))
 {
 cout << "Expression is well parenthesized";
 }
 else
 {
 cout << "Expression is not well parenthesized";
 }
 return 0;
}
