class Solution {
public:
vector<int> findRedundantConnection(vector<vector<int>>& edges){
	vector<int> res(2), parents(1005, -1), absRootV1, absRootV2;
	int n=edges.size(), i, v1, v2;
	for(i=0; i<n; ++i){
		v1 = edges[i][0];
		v2 = edges[i][1];
		while(parents[v1]!=-1){
			v1 = parents[v1];
		}
		while(parents[v2]!=-1){
			v2 = parents[v2];
		}
		if(v1==v2){
			res = edges[i];
		}else{
			parents[v1] = v2;
		}
	}

	return res;
}
};