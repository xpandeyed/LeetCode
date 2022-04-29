class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &visited, vector<int> &color, int node, int par){
        if(par!=-1 and color[node]==color[par]){
            return false;
        }
        if(visited[node]==1){
            return true;
        }
        visited[node]=1;
        if(par!=-1)color[node]-=color[par];
        else color[node]=1;
        for(int x: graph[node]){
            if(!dfs(graph, visited, color, x, node)){
                return false;
            }
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes=graph.size(), i;
        vector<int> color(nodes, 0), visited(nodes, 0);
        //0 means uncolored, unvisited
        //1 means white, visited
        //-1 means black
        for(i=0; i<nodes; ++i){
            if(visited[i]==1){
                continue;
            }
            if(!dfs(graph, visited, color, i, -1)){
                return false;
            }
            
        }          
        return true;
    }
};