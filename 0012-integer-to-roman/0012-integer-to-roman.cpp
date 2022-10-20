class Solution {
public:
    string intToRoman(int num) {
        string res="";
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        vector<string> temp, temp2;
        
        int tens=1, currDigit, i;
        
        while(num>0){
            temp2.clear();
            currDigit=num%10;
            if(currDigit){
                currDigit*=tens;
                i=0;
                while(currDigit>0){
                    if(val[i]>currDigit){
                        i++;
                    }else{
                        temp2.push_back(sym[i]);
                        currDigit-=val[i];
                    }
                    
                }
                
                reverse(temp2.begin(), temp2.end());
                
                for(auto x: temp2){
                    temp.push_back(x);
                }
            }
            num/=10;
            tens*=10;
        }
        
        // for(auto x: temp){
        //     cout << x << " " ;
        // }
        // cout << endl;
        
        reverse(temp.begin(), temp.end());
        
//         for(auto x: temp){
//             cout << x << " " ;
//         }
        for(auto x: temp){
            res+=x;
            
        }
        
        return res;
    }
};