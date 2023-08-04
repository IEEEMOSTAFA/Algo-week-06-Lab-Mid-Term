#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1002;
bool visited[N][N];
int dx[] = {0,0,-1,1};
int dy[] = { 1,-1,0,0};
int level[N][N];
int long_room_len = 0;
bool insidethemaze(pair<int,int>src)

{
    if(src.first >= 0 && src.first<n  && src.second<m && src.second>=0)
    return true;
    return false;
}
void bfs(pair<int,int>src)
{
    int this_room_len = 1;
    queue<pair<int,int>>q;
    visited[src.first][src.second] = true;
    q.push(src);
    while (!q.empty())
    {
        pair<int,int>head;
        head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;
        for(int i=0;i<4;i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            pair<int,int>adj_node = {new_x,new_y};
            if(insidethemaze(adj_node) && visited[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;
                q.push(adj_node);
                this_room_len++;
            }
        }
    }
  long_room_len = max(long_room_len,this_room_len);

}

int main()
{
    cin>>n>>m;
    pair<int,int>src;
    for(int i=0;i<n;i++)
    {
        string input;
        cin>>input;
        
        for(int j=0;j<m;j++)
        {
            if(input[j] == '#')
            visited[i][j] = true;
        }
    }
    int call = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j] == false)
            {
                call++;
                src = {i,j};
                bfs(src);
            }
        }
    }
    cout<<"Rooms - "<<call<<endl;
    cout<<"Length of the longest room  - "<<long_room_len;
    return 0;
}