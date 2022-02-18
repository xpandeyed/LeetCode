class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), res=0, i;
        vector<int> left(n, 0), right(n, 0);
        stack<int> s;
        for(i=0; i<n; ++i){
            if(!s.empty()){
                left[i] = s.top();
            }
            while(!s.empty() && s.top()<=height[i]){
                s.pop();
            }
            if(s.empty()){
                s.push(height[i]);
            }
        }
        
        
        
        
        while(!s.empty()){
            s.pop();
        }
        
        for(i=n-1; i>=0; --i){
            if(!s.empty()){
                right[i] = s.top();
            }
            while(!s.empty() && s.top()<=height[i]){
                s.pop();
            }
            if(s.empty()){
                s.push(height[i]);
            }          
        }
        
        for(i=0; i<n; ++i){
            //cout << left[i] << " " << right[i] << " " << height[i] << endl; 
            if(min(left[i], right[i])>height[i]){
                res+=(min(left[i], right[i])-height[i]);
            }
        }
        return res;
        
    }
};