class LUPrefix {
public:
    int bit[200050], N;
    void update(int idx, int n) {
        while(idx<=n) {
            bit[idx]++;
            idx+=(idx&-idx);
        }
    }
    
    int getSum(int idx) {
        int sum=0;
        while(idx>0) {
            sum+=bit[idx];
            idx-=(idx&-idx);
        }
        return sum;
    }
    
    LUPrefix(int n) {
        N=n;
        for(int i=0; i<=N; i++){
            bit[i]=0;
        }
    }
    
    int res;
    void upload(int video) {
        update(video, N);
        //cout<<video<<" "<<getSum(10)<<"\n";
        int l=0, r=N;
        while(l<=r){
            int mid=l+(r-l)/2;
            //cout<<mid<<" "<<getSum(mid)<<"\n";
            if(mid==getSum(mid)){
                res=mid, l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }
    
    int longest() {
        //cout<<"fahim\n";
        return res;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */