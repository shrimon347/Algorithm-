#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cout << "Enter the number of vertices and Edges: ";
    cin >> V >> E;
    vector<bool> visitedEdge[V];

    vector<int> edges[V];
    cout << "Enter Edges: ";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }

    vector<bool> visited(V, false);

    vector<int> vertexCover;

    for (int u = 0; u < V; u++)
    {

        if (visited[u] == false)
        {
            vertexCover.push_back(u);
            for (auto i : edges[u])
            {
                int v = i;
                if (visited[v] == false)
                {
                    visited[v] = true;
                    visited[u] = true;
                    break;
                }
            }
        }
    }

    cout << "Vertex Cover: ";
    for (auto i : vertexCover)
    {

        cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}

// Input:
// 8 11
// 1 6
// 1 4
// 2 4
// 4 7
// 2 3
// 7 8
// 3 8
// 3 5
// 5 8
// 1 2
// 6 7