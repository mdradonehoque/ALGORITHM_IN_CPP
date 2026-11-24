#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int X;
    cin >> X;
    if(mat[X].size()==0)
        cout<<-1;
    else
        sort(mat[X].begin(),mat[X].end(),greater<int>());
        for(int i=0;i<mat[X].size();i++)
        {
            cout<<mat[X][i]<<" ";
        }
        cout<<endl;
    }
 return 0;   
}