class Solution {
public:
        map<int, vector<int>> createGraphFromEdges(vector<vector<int>>& edges){
        
        //adjacents of i are on res[i]
        
        map<int, vector<int>> res;
        for(auto x: edges){            
            res[x[0]].push_back(x[1]);
            res[x[1]].push_back(x[0]);
        }
        
        
        // print graph
        // for(auto x: res){
        //     cout << x.first << ": " ;
        //     for(auto y: x.second){
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        
        return res;
    }
    
    bool isOddLengthCycle(map<int, vector<int>> graph, vector<int> colors, int n){
        
        vector<bool> visited(n+1, false);
        queue<int> q;
        for(int i=1; i<=n; ++i){
            if(visited[i]){
                continue;
            }
            
            if(colors[i]==0){
                colors[i]=1;
            }
            
            q.push(i);
            
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                visited[curr] = true;
                for(auto x: graph[curr]){
                    if(colors[x]==colors[curr]){
                        return false;
                    }
                    else if(colors[x]==0){
                        colors[x]=(colors[curr]==1?-1:1);
                    }
                    
                    if(visited[x]==false){
                        q.push(x);
                    }
                }
                
            }
        }
        return true;
    }
    
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> colors(n+1, 0);
        //0 means no color
        //1 means black
        //-1 means white
        
        map<int, vector<int>> graph = createGraphFromEdges(dislikes);
        
        return isOddLengthCycle(graph, colors, n);
    }
};