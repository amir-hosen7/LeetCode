class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int a=0, b=0;
        for(auto i:nums1) a^=i;
        for(auto i:nums2) b^=i;
        if(n%2==0 and m%2==0) return 0;
        if(n%2==1 and m%2==1) return a^b;
        if(n%2==1) return b;
        return a;
    }
};

