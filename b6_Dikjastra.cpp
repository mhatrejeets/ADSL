#include <iostream>
using namespace std;
class Graph
{
public:
    int g[10][10], vertices, edges;
    Graph()
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                g[i][j] = 999;
    }

    void create()
    {
        int u, v, w;

        cout << "\nEnter vertices and edges of graph\n";
        cin >> vertices >> edges;
        for (int i = 0; i < edges; i++)
        {
            cout << "\nEnter " << i + 1 << " Edge with its weight: ";
            cin >> u >> v >> w;
            g[u][v] = g[v][u] = w;
        }
    }

    void dijkstra()
    {
        int visited[10] = {}, pre[10], distance[10], count, nextnode, min = 999;

        for (int i = 0; i < vertices; i++)
        {
            distance[i] = g[0][i];
            pre[i] = 0;
        }

        distance[0] = 0;
        visited[0] = 1;
        count = 1;

        while (count < vertices - 1)
        {
            min = 999;
            for (int i = 0; i < vertices; i++)
            {
                if (distance[i] < min && visited[i] == 0)
                {
                    min = distance[i];
                    nextnode = i;
                }
            }

            visited[nextnode] = 1;
            for (int i = 0; i < vertices; i++)
            {
                if ((distance[i] > min + g[nextnode][i]) && visited[i] != 1)
                {
                    distance[i] = min + g[nextnode][i];
                    pre[i] = nextnode;
                }
            }
            count++;
        }

        for (int i = 0; i < vertices; i++)
        {
            cout << "\nDistance from 0 to " << i << ": ";
            cout << distance[i];
        }
    }
};

int main()
{
    Graph g;
    g.create();
    g.dijkstra();
    return 0;
}