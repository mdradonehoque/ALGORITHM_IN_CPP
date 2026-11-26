#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

bool vis[N];
vector<int> adj[N];
int parent[N];
bool ans;

void dfs(int par)
{
    vis[par] = true;

    for (int child : adj[par])
    {
        if (vis[child] == true && parent[par] != child)
        {
            ans = true;
        }

        if (vis[child] == false)
        {
            parent[child] = par;
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    ans = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    if (ans)
        cout << "Cycle detected";
    else
        cout << "Cycle not detected";

    return 0;
}