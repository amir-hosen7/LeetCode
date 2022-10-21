class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       map<int,int>m; k++;
        int n = nums.size();
        
        for(int i = 0;i<min(k,n);i++)
        {
            if(m[nums[i]]) return true;
            m[nums[i]]++;
        }
         for(int i = k;i<n;i++)
        {
            m[nums[i-k]]--;
            if(m[nums[i]]) return true;
            m[nums[i]]++;
        }   
         
        
        return false;
    }
};