#include <bits/stdc++.h>
using namespace std;

bool bfs(int **graph, int s, int t, int parent[], int V)
{
    vector<bool> visited(V, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && graph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(int **graph, int s, int t, int V)
{
    int u, v;

    int parent[V];

    int max_flow = 0;
    while (bfs(graph, s, t, parent, V))
    {

        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, graph[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{

    int V, E;
    cout << "Enter the number of vertices and Edges: ";
    cin >> V >> E;

    int **graph;

    graph = new int *[V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }
    cout << "Enter u v w: ";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    cout << "Enter source and sink: ";
    int s, t;
    cin >> s >> t;
    cout << "The maximum possible flow is "
         << fordFulkerson(graph, s, t, V) << endl;

    return 0;
}

// input:
// 6 10
//  0 1 16
//  0 2 13
//  1 2 10
//  2 1 4
//  1 3 12
//  2 4 14
//  3 2 9
//  4 3 7
//  3 5 20
//  4 5 4
// 0 5