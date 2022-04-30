class Solution {
public:
    void dfs(vector<bool> &visited, vector<vector<int>> &rooms, int room){
        if(visited[room]){
            return ;
        }
        visited[room]=true;
        for(int x: rooms[room]){
            dfs(visited, rooms, x);
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n, false);
        dfs(visited, rooms, 0);
        return find(visited.begin(), visited.end(), false)==visited.end();
    }
};