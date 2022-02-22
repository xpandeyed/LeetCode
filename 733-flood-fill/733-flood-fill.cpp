class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;
        int startColor = image[sr][sc], rows = image.size(), cols=image[0].size();
        image[sr][sc]=newColor;
        q.push(pair<int, int>(sr, sc));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            
            visited[x][y] = true;
            
            q.pop();
            
            if(x>0 && (!visited[x-1][y] && image[x-1][y]==startColor)){
                image[x-1][y]=newColor;
                q.push(pair<int, int>(x-1, y));
            }
            if(x<rows-1 && (!visited[x+1][y] && image[x+1][y]==startColor)){
                image[x+1][y]=newColor;
                q.push(pair<int, int>(x+1, y));
            }
            if(y>0 && (!visited[x][y-1] && image[x][y-1]==startColor)){
                image[x][y-1]=newColor;
                q.push(pair<int, int>(x, y-1));
            }
            if(y<cols-1 && (!visited[x][y+1] && image[x][y+1]==startColor)){
                image[x][y+1]=newColor;
                q.push(pair<int, int>(x, y+1));
            }
        }
        
        return image;
    }
};