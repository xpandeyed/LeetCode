class Solution {
public:
    int dp[101][21][101];
    
    int costing(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target,int i,int clrp,int num)
    {
        
        
        
        if(num>target)
            return 1e8;
        if(i==m)
        {
            if(num==target)
                return 0;
            return 1e8;
        }
        
        if(dp[i][clrp][num]!=-1)
            return dp[i][clrp][num];
        if(houses[i]!=0)
        {   
            if(clrp==houses[i])
                return dp[i][clrp][num]=costing(houses,cost,m,n,target,i+1,houses[i],num);
            return dp[i][clrp][num]=costing(houses,cost,m,n,target,i+1,houses[i],num+1);
        }
        else
        {
            int ans=1e8;
            for(int j=0;j<cost[i].size();j++)
            {   
                if(clrp==j+1)
                ans=min(ans,cost[i][j]+costing(houses,cost,m,n,target,i+1,j+1,num));
                else
                    ans=min(ans,cost[i][j]+costing(houses,cost,m,n,target,i+1,j+1,num+1));

            }
             return dp[i][clrp][num]=ans;
        }
       
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        /*
            if house is colored last summer then we dont care else we color the houses one by one with all colors and see which combo gives minimum cost
            
            
            some conditions are that neighbourhood dont increase if prev color is same
         also color available are 1 to n
        color house i cost[i][j]
        */
        memset(dp,-1,sizeof(dp));
        int ans= costing(houses,cost,m,n,target,0,0,0);
        if(ans>=1e8)
            return -1;
        return ans;
        
    }
};