class NumArray {
public:
    vector<int> tree, v;
    int siz;
    NumArray(vector<int>& nums) {
        v=nums;
        siz=nums.size();
        tree.resize(siz+5, 0);
        for(int i=1; i<=siz; i++){
            insert(i, nums[i-1]);
        }
    }
    
    void insert(int idx, int val){
        while(idx<=siz){
            tree[idx]+=val;
            idx+=(idx&-idx);
        }
    }
    
    void update(int index, int val) {
        index++;
        int prev=v[index-1];
        v[index-1]=val;
        while(index<=siz){
            tree[index]-=prev;
            tree[index]+=val;
            index+=(index & -index);
        }
    }
    
    int getSum(int idx){
        int sum=0;
        while(idx>0){
            sum+=tree[idx];
            idx-=(idx & -idx);
        }
        return sum;
    }
    int sumRange(int left, int right) {
        left++, right++;
        return getSum(right)-getSum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */