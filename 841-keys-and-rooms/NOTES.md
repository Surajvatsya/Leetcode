```
class Solution {
public:
void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int x)
{
int i;
for(i=0;i<rooms[x].size();i++)
{
if(vis[rooms[x][i]])
continue;
vis[rooms[x][i]]=true;
dfs(rooms, vis, rooms[x][i]);
}
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
vector<bool> visited(rooms.size(), false);
visited[0]=true;
dfs(rooms, visited, 0);
int i;
for(i=0;i<visited.size();i++)
{
if(!visited[i])
return false;
}
return true;
}
};
```