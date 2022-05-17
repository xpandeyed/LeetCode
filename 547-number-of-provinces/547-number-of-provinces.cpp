class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int node, int nodes){
        if(visited[node]){
            return;
        }
        visited[node]=true;
        int i=0;
        for(i=0;i<nodes; ++i){
            if(isConnected[node][i] and !visited[i]){
                dfs(isConnected, visited, i, nodes);
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces=0;
        
        int nodes=isConnected.size(), i;
        
        vector<bool> visited(nodes, false);
        
        for(i=0;i<nodes; ++i){
            if(!visited[i]){
                dfs(isConnected, visited, i, nodes);
                provinces++;
            }
        }
        
        return provinces;
    }
};