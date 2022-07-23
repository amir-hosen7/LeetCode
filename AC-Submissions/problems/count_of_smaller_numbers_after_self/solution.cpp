class Solution {
public:
    static const int N=1e5;
    vector<int> tree[3*N];
    
    void build(int node, int b, int e, vector<int>& v){
        if(b==e){
            tree[node].push_back(v[b]);
            return;
        }
        int mid=b+(e-b)/2;
        build(node*2, b, mid, v);
        build(node*2+1, mid+1, e, v);
        merge(tree[node*2].begin(), tree[node*2].end(), tree[node*2+1].begin(), tree[node*2+1].end(), back_inserter(tree[node]));
    }
    
    int query(int node, int b, int e, int L, int R, int val){
        if(b>R or e<L or b>e) return 0;
        if(b>=L and e<=R){
            int idx=lower_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
            return idx;
        }
        int mid=b+(e-b)/2;
        return query(node*2,b,mid,L,R,val)+query(node*2+1,mid+1,e,L,R,val);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        build(1,0,n-1,nums);
        for(int i=0; i<n; i++){
            int ans=query(1,0,n-1,i,n-1,nums[i]);
            nums[i]=ans;
        }
        return nums;
    }
};

