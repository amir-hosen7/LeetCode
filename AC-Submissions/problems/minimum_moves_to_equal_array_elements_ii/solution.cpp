class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size(), ans=0;
        sort(nums.begin(), nums.end());
        int mid=n/2;
        int median=nums[mid];
        if(n%2==0){
            median=(nums[mid-1]+nums[mid])/2;
        }
        for(int i=0; i<n; i++){
            ans+=abs(nums[i]-median);
        }
        return ans;
    }
};


