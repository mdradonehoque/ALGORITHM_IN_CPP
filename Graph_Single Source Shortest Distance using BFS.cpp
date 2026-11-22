#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[2000];
bool visited[2000];
int lev[2000];
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
    int src, dst;
    cin >> src >> dst;
    bfs(src);
    // for(int i=0;i<n;i++){
    //  cout<<i<<"->"<<lev[i]<<endl;
    // }
    cout << lev[dst] << endl;
    return 0;
}