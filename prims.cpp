#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> g[N];
    int a, b, w;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    int parent[N];

    int key[N];

    bool minSet[N];

    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        minSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < N - 1; i++)
    {
        int mini = INT_MAX, u;

        for (int v = 0; v < N; v++)
        {
            if (minSet[v] == false && key[v] < mini)
            {
                mini = key[v];
                u = v;
            }
        }
        minSet[u] = true;

        for (auto it : g[u])
        {

            int v = it.first;
            int w = it.second;

            if (!minSet[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " -- " << i << endl;
    }
}