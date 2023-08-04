#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 500;
int dist[N];
int n,m;
class edge{
    public:
    int u,v,w;
};
vector<edge>Edge;
bool cycle_check()
{
    for(int i =1;i<=n;i++)
    {
        for(auto j:Edge)
        {
            if(dist[j.v]>dist[j.u] + j.w)
            {
                dist[j.v] = dist[j.u] + j.w;
                if(i == n)
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    { 
        int u,v,w;
        cin>>u>>v>>w;
        Edge.push_back({u,v,w});

    
    
    }
    for(int i=0;i<N;i++)
    {
        dist[i] = INF;
    }
    int src = 1;
    dist[src] = 0;
    if(cycle_check())
    {
        cout<<"Yes"<<endl;

    }
    else
    {
        cout<<" NO"<<endl;

    }
    return 0;

}