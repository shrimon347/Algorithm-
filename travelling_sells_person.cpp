
#include <bits/stdc++.h>
using namespace std;
#define V 100

int travllingSalesmanProblem(int graph[][V], int v, int s)
{

    vector<int> vertex;
    for (int i = 0; i < v; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;
    do
    {

        int current_pathweight = 0;

        int k = s;
        for (int i = 0; i < (int)vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        min_path = min(min_path, current_pathweight);

    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

// Driver Code
int main()
{

    int n = 0;
    cin >> n;

    int graph[V][V];
    int u, v, wt;
    for (int i = 0; i < (n - 1) * n / 2; i++)
    {
        cin >> u >> v >> wt;
        graph[u][v] = wt;
        graph[v][u] = wt;
    }

    int s = 0;
    cout << travllingSalesmanProblem(graph, n, s) << endl;
    return 0;
}

// Input:
// 4
// 0 1 10
// 0 2 15
// 0 3 20
// 1 2 35
// 1 3 25
// 2 3 30