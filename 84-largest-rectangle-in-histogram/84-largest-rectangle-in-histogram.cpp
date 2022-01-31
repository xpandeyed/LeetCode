class Solution {
public:
    
    int oneStack(vector<int>& heights){
        stack<int> s;
        int n=heights.size(), i, res=0, curr, tp, r, l;
        
        for(i=0; i<n; ++i){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                tp = s.top();
                s.pop();
                curr = heights[tp];
                r=0;
                r+=(curr*(i-tp-1));
                l=0;
                if(!s.empty()){
                    l+=(curr*(tp-s.top()-1));
                }else{
                    l+=(curr*tp);
                }
                curr+=l;
                curr+=r;
                
                                
                //cout << heights[i] << " " << curr << endl;
                
                
                res = max(res, curr);
            }
            
            s.push(i);
        }
        
        
        while(!s.empty()){
            tp = s.top();
            s.pop();
            curr = (n-tp)*heights[tp];
            if(!s.empty()){
                curr+=(heights[tp]*(tp-s.top()-1));
            }else{
                curr+=(heights[tp]*tp);
            }
            res = max(res, curr);
        }
        return res;
    }
    
    
    int twoArrayOneStack(vector<int>& heights){
        stack<int> s1, s2 ;
        int n=heights.size();
        vector<int> v1, v2(n, 0);
        
        for(int i=0; i<n; ++i){
            while(!s1.empty() && heights[s1.top()]>=heights[i]){
                s1.pop();
            }
            if(s1.empty()){
                v1.push_back(-1);
            }else{
                v1.push_back(s1.top());
            }
            s1.push(i);
        }
        for(int i=n-1; i>-1; --i){
            while(!s2.empty() && heights[s2.top()]>=heights[i]){
                s2.pop();
            }
            if(s2.empty()){
                v2[i]=-1;
            }else{
                v2[i]=s2.top();
            }
            s2.push(i);
        }
        int res = 0;
        for(int i=0; i<n; ++i){
            int l=v1[i];
            int la =0;
            int r = v2[i];
            int ra=0;
            if(l==-1){
                la=i*heights[i];
            }else{
                la=(i-l-1)*heights[i];
            }
            if(r==-1){
                ra=(n-i-1)*heights[i];
            }else{
                ra=(r-i-1)*heights[i];
            }
            int ta = heights[i]+la+ra;
            res = max(res, ta);
        }
        // int i = 1;
        // int count = heights[0];
        // while(i<n && heights[i]>=heights[0]){
        //     count+=heights[0];
        //     i++;
        // }
        // res=max(res, count);
        // i=n-2;
        // count=0;
        // count=heights[n-1];
        // while(i>=0 && heights[i]>=heights[n-1]){
        //     count+=heights[n-1];
        //     --i;
        // }
        // res=max(res, count);
        return res;
    }
    
    
    
    
    int largestRectangleArea(vector<int>& heights) {
        return oneStack(heights);
    }
    
};