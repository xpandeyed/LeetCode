class Solution {
public:
    int nodes;
    unordered_set<int> cycle;
    unordered_set<int> path;
    unordered_set<int> safe;
    
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited){
        visited[node]=true;
        for(int x: graph[node]){
            if(path.find(x)!=path.end() or cycle.find(x)!=cycle.end()){
                for(int y: path){
                    cycle.insert(y);
                }
            }
            else if(!visited[x]){
                path.insert(x);
                dfs(x, graph, visited);
                path.erase(x);
            }
        }
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        nodes=graph.size();
        vector<bool> visited(nodes, false);
        for(int i=0;i<nodes; ++i){
            if(!visited[i]){
                // cout << "DFS : " << endl; 
                path.insert(i);
                dfs(i, graph, visited);
                path.erase(i);
            }
        }
        vector<int> res;
        for(int i=0;i<nodes; ++i){
            if(cycle.find(i)==cycle.end()) res.push_back(i);
        }
        return res;
        
        
        
    }
};