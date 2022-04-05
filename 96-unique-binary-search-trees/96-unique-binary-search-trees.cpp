class Solution {
public:
    int rec(int start, int end, vector<vector<int>> &data){
        if(start>=end){
            return 1;
        }
        if(data[start][end]!=-1){
            return data[start][end];
        }
        int res =0, i;
        for(i=start; i<=end; ++i){
            res+=(rec(start, i-1, data)*rec(i+1, end, data));
        }
        return data[start][end] = res;
    }
    int numTrees(int n) {
        vector<vector<int>> data(n+1, vector<int>(n+1, -1));
        return rec(1, n, data);
    }
};