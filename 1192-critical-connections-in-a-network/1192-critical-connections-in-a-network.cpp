class Solution {
public:
    map<int, vector<int>> m;
    int time=0;
    vector<vector<int>> res;
    
    void createGraph(vector<vector<int>>& connections){
        for(auto edge: connections){
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
    }
    
    void dfs(int node, int parent, vector<int> &low, vector<int> &disc){
        if(disc[node]!=-1){
            return;
        }
        disc[node]=time;
        low[node]=time;
        time++;
        for(auto adj: m[node]){
            if(disc[adj]==-1){
                dfs(adj, node, low, disc);
                low[node]=min(low[node], low[adj]);
                if(low[adj]>disc[node]){
                    vector<int> temp {node, adj};
                    res.push_back(temp);
                }
            }
            else if(adj!=parent){
                low[node]=min(low[node], disc[adj]);
            }
        }
        
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        createGraph(connections);
        vector<int> low(n, -1), disc(n,-1);
        dfs(0, -1, low, disc);
        return res;
    }
};