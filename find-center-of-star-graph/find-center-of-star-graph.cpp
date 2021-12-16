class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> connections(edges.size()+1, 0);
        for(int i=0; i<edges.size(); ++i){
            connections[edges[i][0]-1]++;
            connections[edges[i][1]-1]++;
        }
        return find(connections.begin(), connections.end(), edges.size())-connections.begin()+1;
    }
};