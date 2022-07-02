class Solution {
public:
    static const int mod=1e9+7;
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        sort(H.begin(), H.end());
        sort(V.begin(), V.end());
        long long hMax=0,hsz=H.size();
        for(int i=0; i<hsz;i++){
            if(i==0){
                hMax=H[i];
            }
            else{
                if((H[i]-H[i-1])>hMax){
                    hMax=H[i]-H[i-1];
                }
            }
        }
        if((h-H[hsz-1])>hMax){
            hMax=h-H[hsz-1];
        }
        long long vMax=0,vsz=V.size();
        for(int i=0; i<vsz;i++){
            if(i==0){
                vMax=V[i];
            }
            else{
                if((V[i]-V[i-1])>vMax){
                    vMax=V[i]-V[i-1];
                }
            }
        }
        if((w-V[vsz-1])>vMax){
            vMax=w-V[vsz-1];
        }
        return (hMax*vMax)%mod;
    }
};