class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        hC.push_back(h);
        vC.push_back(w);
        long long int i, j, nVC=(long long int)vC.size(), nHC=(long long int)hC.size(), pVC=0, mHG=0, mVG=0, pHC=0, res=0, mod=1e9+7;
        sort(hC.begin(), hC.end());
        sort(vC.begin(), vC.end());
        for(i=0;i<nHC; ++i){
            // cout <<  hC[i]<< " " << pHC << endl;
            mHG = max(mHG, hC[i]-pHC);
            pHC=hC[i];
        }
        for(i=0;i<nVC;++i){
            mVG = max(mVG, vC[i]-pVC);
            pVC=vC[i];
        }
        // cout << mVG  << " " << mHG << endl;
        return ((mVG)*(mHG))%mod;
    }
};