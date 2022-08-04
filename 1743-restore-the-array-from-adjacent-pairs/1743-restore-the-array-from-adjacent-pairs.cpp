class Solution {
public:
    map<int, vector<int>> graph;
    
    vector<int> res;
    
    set<int> visited;
    
    void makeGraph(vector<vector<int>>& ap){
        for(auto x: ap){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
    }
    
    void dfs(int node){
        if(visited.find(node)!=visited.end()) return;
        visited.insert(node);
        res.push_back(node);
        for(auto x: graph[node]){
            dfs(x);
        }
    }
    
    
    vector<int> restoreArray(vector<vector<int>>& ap) {
        makeGraph(ap);
        for(auto x: graph){
            if(x.second.size()==1){
                dfs(x.first);
                break;
            }
        }
        return res;
    }
};