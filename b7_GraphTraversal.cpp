#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;

void addEdge(int x, int y)//CREATION OF ADJACENT MATRIX
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

void bfs(int start)
{
    vector<bool> visited(adj.size(), false);//CHECKING IF THE NODE IS VISITED OR NOT
    vector<int> q;//MAINTAINING A QUEUE WITH THE HELP OF A VECTOR

    q.push_back(start);
    int vis;
    visited[start] = true;

    while (!q.empty())
    {
        vis = q[0];
        cout<<vis<<" ";
        q.erase(q.begin());
        
        for(int i=0; i<adj[vis].size(); i++){
            if(adj[vis][i]==1 && (!visited[i])){
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int v = 5;

    adj = vector<vector<int>>(v, vector<int>(v,0));//v*v vector
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);

    bfs(0);
}