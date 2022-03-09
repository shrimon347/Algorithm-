#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int u;
    int v;
    int w;
    Node(int f, int s, int wt)
    {
        u = f;
        v = s;
        w = wt;
    }
};

bool comp(Node a, Node b)
{
    return a.w < b.w;
}

int findPair(int u, vector<int> &parent)
{
    if (parent[u] == u)
        return u;
    return parent[u] = findPair(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int x = findPair(u, parent);
    int y = findPair(v, parent);
    if (x == y)
    {
        parent[y] = x;
        rank[x]++;
    }
    if (rank[x] > rank[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
    }
}

void kruskalsAlgo(vector<Node> g, int N, int M)
{
    sort(g.begin(), g.end(), comp);

    vector<int> parent(N);
    vector<int> rank(N, 0);

    for (int i = 0; i < N; i++)
        parent[i] = i;

    vector<pair<int, int>> mst;
    int minCost = 0;

    for (auto it : g)
    {
        if (findPair(it.u, parent) != findPair(it.v, parent))
        {
            minCost += it.w;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
    cout << "Min Cost: " << minCost << endl;

    for (auto it : mst)
    {
        cout << it.first << " " << it.second << endl;
    }
}

int main()
{

    int N, M;
    cin >> N >> M;

    vector<Node> g;
    int a, b, w;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> w;
        g.push_back(Node(a, b, w));
    }
    kruskalsAlgo(g, N, M);
}

// Input
//  8 13
//  1 2 1
//  1 3 1
//  1 4 3
//  3 4 4
//  3 5 2
//  4 5 4
//  4 6 5
//  5 7 2
//  6 7 2
//  6 8 6
//  7 8 7
//  2 6 3
//  2 8 6