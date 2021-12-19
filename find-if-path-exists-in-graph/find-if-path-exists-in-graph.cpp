class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if(start==end){
            return true;
        }
        vector<vector<int>> adjacencyList(n);
        for(int i=0; i<edges.size(); ++i){
            adjacencyList[edges[i][0]].push_back(edges[i][1]);
            adjacencyList[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(start);
        while(!q.empty()){
            int curr = q.front();
            visited[curr]=true;
            q.pop();
            for(auto x: adjacencyList[curr]){
                if(!visited[x]){
                    q.push(x);
                }
                if(x==end){
                    return true;
                }
                
            }
        }
        return false;
    }
};