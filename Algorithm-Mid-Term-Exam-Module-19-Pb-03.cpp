#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const long long int INF = 1e18;
int n,m,q;
long long int adj_matrix[N][N];
void floyed_warshall()
{
    for(int k=1;k<=n;k++)
    {
        for(int u=1;u<=n;u++)
        {
            for(int v=1;v<=n;v++)
            {
                if(adj_matrix[u][v]> adj_matrix[u][k]+ adj_matrix[k][v])
                {
                    adj_matrix[u][v] = adj_matrix[u][k]+ adj_matrix[k][v];
                }

            }
        }
    }
}

int main()
{
 cin>>n>>m>>q;
 for(int i=1;i<=n;i++)
 {
    for(int j=1;j<=n;j++)
    {
        adj_matrix[i][j] = INF;
    }
 }
 for(int i=1;i<=n;i++)
 {
    adj_matrix[i][i] = 0;
 }
 for(int i=0;i<m;i++)
 {
    int u,v;
    long long w;
    cin>>u>>v>>w;
    adj_matrix[u][v] = min(w,adj_matrix[u][v]);
    adj_matrix[v][u] = min(w,adj_matrix[v][u]);
 }
 floyed_warshall();
 for(int i=1;i<=q;i++)
 {
    int u,v;
    cin>>u>>v;
    if(adj_matrix[u][v] == INF)
    cout<< -1<<endl;
    else
    cout<<adj_matrix[u][v]<<endl;
 }
 return 0;
}