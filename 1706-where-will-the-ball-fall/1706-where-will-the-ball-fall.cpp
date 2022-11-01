class Solution {
public:
    // idea: we can simulate the movement of each ball
    // if a ball is stuck at some point, then it would be -1
    // otherwise, get the final destination column
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans;
        // iterate each column
        for (int col = 0; col < n; col++) {
            int cur_col = col;
            // iterate each row
            for (int cur_row = 0; cur_row < m; cur_row++) {
                // the next column would be the current column + the value of the current cell
                // e.g. column 0 + 1 = column 1 (move to the right)
                // e.g. column 3 - 1 = column 2 (move to the left)
                int next_col = cur_col + grid[cur_row][cur_col];
                // after that we need to check if the ball gets stuck at the same column
                // and there are three cases
                // 1. the ball on the leftmost column is moving to the left
                // hence, we check `next_col < 0`
                // 2. the ball on the rightmost column is moving to the right
                // hence, we check `next_col >= n`
                // 3. the ball is stuck at a V shape position
                // e.g. ball 2 and ball 3 in column 2 and column 3 in row 0
                // hence, we check if the if grid[cur_row][cur_col] is different than grid[cur_row][next_col]
                if (next_col < 0 || next_col >= n || grid[cur_row][cur_col] ^ grid[cur_row][next_col]) {
                    // the ball is stuck at some point, which means it couldn't reach to the end
                    // hence, we can set -1 and break here
                    cur_col = -1;
                    break;
                }
                // continue the above process with the updated cur_col
                cur_col = next_col;
            }
            // the ball reaches to the end,
            // cur_col is the final destination
            ans.push_back(cur_col);
        }
        return ans;
    }
};