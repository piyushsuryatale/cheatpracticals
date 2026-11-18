// Q16. Flight graph using adjacency list. Check whether the graph is connected (DFS).
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
string city[20];
vector<pair<int, int> > adj[20]; // adjacency list: (destination city, cost)
int getIndex(string name)
{
 for(int i = 0; i < n; i++)
 if(city[i] == name)
 return i;
 return -1;
}
void dfs(int u, bool visited[])
{
 visited[u] = true;
 for(int i = 0; i < (int)adj[u].size(); i++)
 {
 int v = adj[u][i].first;
 if(!visited[v])
 dfs(v, visited);
 }
}
bool isConnected() // DFS starting from city 0
{
 bool visited[20] = {false};
 dfs(0, visited);
 for(int i = 0; i < n; i++)
 if(!visited[i])
 return false;
 return true;
}
int main()
{
 int e, cost;
 string src, dest;
 cout << "Enter number of cities: ";
 cin >> n;
 cout << "Enter city names: ";
 for(int i = 0; i < n; i++)
 cin >> city[i];
 cout << "Enter number of flights: ";
 cin >> e;
 for(int i = 0; i < e; i++)
 {
 cout << "Enter source, destination and cost: ";
 cin >> src >> dest >> cost;
 int u = getIndex(src), v = getIndex(dest);
 if(u == -1 || v == -1)
 {
 cout << "Invalid city\n";
 i--;
 continue;
 }
 adj[u].push_back(make_pair(v, cost));
 adj[v].push_back(make_pair(u, cost));
 }
 if(isConnected())
 cout << "Graph is connected";
 else
 cout << "Graph is not connected";
 return 0;
}
