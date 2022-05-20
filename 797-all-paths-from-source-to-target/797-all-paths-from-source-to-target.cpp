class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int> path, vector<vector<int>> &res, int node, int t, set<int> recStack){
        // cout << node << endl;
        if(node==t){
            res.push_back(path);
            return ;
        }
        for(auto n: graph[node]){
            if(recStack.find(n)==recStack.end()){
                recStack.insert(n);
                path.push_back(n);
                dfs(graph, path, res, n, t, recStack);
                recStack.erase(n);
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        set<int> rs;
        rs.insert(0);
        int t = graph.size()-1;
        vector<vector<int>> res;
        vector<int> path = {0};
        dfs(graph, path, res, 0, t, rs);
        return res;
        
    }
};