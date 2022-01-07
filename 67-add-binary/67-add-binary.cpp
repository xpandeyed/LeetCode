class Solution {
public:
string addBinary(string a, string b) {
    	if(a.size()==0){
    		return b;
    	}
    	if(b.size()==0){
    		return a;
    	}
        int carry = 0;
        string res= "";
        int n = a.size()-1, m = b.size()-1;
        while(n>=0 && m>=0){
            int curr = a[n]+b[m]-96+carry;
            if(curr==2){
                curr=0;
                carry=1;
            }else if(curr==3){
                curr=1;
                carry=1;
            }else if(curr==1){
                carry=0;
            }
            res+=(curr+48);
            n--;
            m--;
            cout << "res is: " << res << endl;
        }
        while(n>=0){
            int curr = a[n]-48+carry;
            if(curr==2){
                curr=0;
                carry=1;
            }else if(curr==3){
                curr=1;
                carry=1;
            }else if(curr==1){
                carry=0;
            }
            res+=(curr+48);
            cout << "res is: " << res << endl;
            n--;
        }
        while(m>=0){
            int curr = b[m]-48+carry;
            if(curr==2){
                curr=0;
                carry=1;
            }else if(curr==3){
                curr=1;
                carry=1;
            }else if(curr==1){
                carry=0;
            }
            res+=(curr+48);
            m--;
            cout << "res is: " << res << endl;
        }
        if(carry!=0){
        	res+=49;
        }
        int l=0, r=res.size()-1;
        while(l<=r){
            swap(res[l], res[r]);
            l++;
            r--;
        }

        return res;
        
    }
};