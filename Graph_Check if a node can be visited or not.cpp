#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[2000];
bool visited[2000];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
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
            }
        }
    }
    cout<<endl;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    int src,dst;
    cin>>src>>dst;
    bfs(src);
    if(visited[dst]){
        cout<<"YES";
    }
    else
        cout<<"NO";
    return 0;
}