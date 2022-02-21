class Solution {
public:
    int row(vector<vector<int>>& matrix, int target){
        int l=0, h=matrix.size()-1, cols=matrix[0].size();
        int mid;
        while(l<=h){
            mid = (l+h)/2;
            
            if(matrix[mid][0]<=target && matrix[mid][cols-1]>=target){
                return mid;
            }
            else if(matrix[mid][0]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        return mid;
    }
    
    bool binarySearch(vector<int> nums, int target){
        int l=0, h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        return false;
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = row(matrix, target);
        if(matrix[r][0]==target){
            return true;
        }
        cout << r ;
        return binarySearch(matrix[r], target);
    }
    
};