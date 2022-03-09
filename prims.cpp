#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int to, weight;
};

vector<Edge> G[100];

void PrimBro(int n, int e)
{

    vector<int> vis(n + 1, 0);
    set<pair<int, int>> ms;

    ms.insert({0, 1});
    int cost = 0, connected_edge = 0;

    while (!ms.empty())
    {
        auto top = ms.begin();
        ms.erase(ms.begin());
        int u = top->second;

        if (vis[u] == 1)
            continue;

        cost += top->first;
        vis[u] = 1;

        connected_edge++;
        if (connected_edge == n)
            break;

        for (Edge i : G[u])
        {
            if (!vis[i.to])
            {
                ms.insert({i.weight, i.to});
            }
        }
    }

    cout << cost << endl;
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    cout << "minimum cost is : ";
    PrimBro(n, e);

    return 0;
}


// input


// 9 14
// 1 2 4
// 1 3 8
// 2 3 11
// 2 5 8
// 5 4 2
// 4 3 7
// 3 7 1
// 4 7 6
// 5 8 4
// 7 8 2
// 6 8 14
// 6 9 9
// 8 9 10
// 5 6 7

//ans =37
