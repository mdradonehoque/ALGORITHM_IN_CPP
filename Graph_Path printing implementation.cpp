#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[2000];
bool visited[2000];
int lev[2000];
int parent[2000];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    lev[src] = 0;

    while (!q.empty())
    {
        // ber kore ana
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (visited[child] == false)
            {
                q.push(child);
                // cout<child<<" ";
                visited[child] = true;
                lev[child] = lev[par] + 1;
                parent[child] = par;
            }
        }
    }
    cout << endl;
}
int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    memset(lev, -1, sizeof(lev));
    memset(parent, -1, sizeof(parent));
    int src, dst;
    cin >> src >> dst;
    bfs(src);
     vector<int> path;
    int node = dst;
    while (node != -1)
    {
        cout << node << " ";
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
    {
        cout << x << " ";
    }
    return 0;
    return 0;
}
