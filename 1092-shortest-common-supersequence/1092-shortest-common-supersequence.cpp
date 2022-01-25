class Solution {
public:
    string finalizer(string s1, string s2, string lcs){
	int i=0, j=0, k=0, n1=s1.size(), n2=s2.size(), n3=lcs.size();
	string res = "";
	while(i<n1 && (j<n2 && k<n3)){
		while(s1[i]!=lcs[k]){
			res+=s1[i];
			i++;
		}
		while(s2[j]!=lcs[k]){
			res+=s2[j];
			j++;
		}
		res+=lcs[k];
		i++;
		j++;
		k++;
	}
    while(i<n1){
		res+=s1[i];
		i++;
	}
	while(j<n2){
		res+=s2[j];
		j++;
	}
	return res;
}
    
    string dynamic(string a, string b){
	vector<vector<string>> res(a.size()+1, vector<string>(b.size()+1, ""));
	int i, j, n1=a.size(), n2=b.size();
	for(i=0; i<n1+1; ++i){
		for(j=0; j<n2+1; ++j){
			if(i==0 || j==0){
				res[i][j]="";
				continue;
			}
			if(a[i-1] == b[j-1]){
				res[i][j] = a[i-1] + res[i-1][j-1];
			}else{
				res[i][j] = res[i-1][j].size()>res[i][j-1].size()?res[i-1][j]:res[i][j-1];
			}
		}
	}
	//cout << " * " << res[n1][n2] << " * " ; 
	i=0, j=res[n1][n2].size()-1;
	while(i<j){
		swap(res[n1][n2][i], res[n1][n2][j]);
		i++;
		j--;
	}
	return res[n1][n2];
}
    
    string shortestCommonSupersequence(string str1, string str2) {
        return finalizer(str1, str2, dynamic(str1, str2));
    }
};