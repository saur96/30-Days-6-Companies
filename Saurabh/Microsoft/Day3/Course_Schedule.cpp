class Solution {
public:
    bool dfs(int j,vector<bool>&visited, vector<bool>&currvisited, vector<int>adj[])
    {
        visited[j] = true;
        currvisited[j] = true;
        vector<int>data = adj[j];
        for(auto x:data)
        {
            if(!visited[x]){
                if(dfs(x,visited,currvisited,adj)){
                    return true;
                }
            }
            else if(visited[x]&&currvisited[x]){
                return true;
            }
        }
        currvisited[j]=false;
        return false;
    }
    
    bool canFinish(int num, vector<vector<int>>& p) {
        int n = num;
        vector<bool>visited(n,false),currvisited(n,false);
        vector<int>adj[n];
        for(auto x:p)
        {
            vector<int>data = x;
            int a = data[0];
            int b = data[1];
            adj[a].push_back(b);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,visited,currvisited,adj))
                {
                    return 0;
                }
            }
        }
        return 1;
        
    }
};
