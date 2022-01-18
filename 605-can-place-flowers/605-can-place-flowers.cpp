class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0){
            return true;
        }
        int count=0, i=0, s=flowerbed.size();
        
        if(s==1){
            if(flowerbed[0]==0 && n<=1){
                return true;
            }
            else{
                return false;
            }
        }
        
        
        while(i<s){
            if(count>=n){
                break;
            }
            
            if(i==0){
                if(flowerbed[i+1]!=1  && flowerbed[i]==0){
                    count++;
                    i+=2;
                    continue;
                }

            }
            if(i==s-1){
                if(flowerbed[i-1]!=1 && flowerbed[i]==0){
                    count++;
                    i+=2;
                    continue;
                }
            }
            if(i>0 && i<s-1){
                if(flowerbed[i]==0 && (flowerbed[i-1]==0 && flowerbed[i+1]==0)){
                count++;
                i+=2;
                continue;
            }
            }
            
            i++;
        }
        return count>=n;
    }
};