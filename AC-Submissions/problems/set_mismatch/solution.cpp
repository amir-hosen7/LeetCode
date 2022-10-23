class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, bool> mark;
        int sum=0, duplicate;
        for(auto i:nums){
            sum+=i;
            if(mark[i]){
                duplicate=i;
            }
            mark[i]=1;
        }
        int missing=(n*(n+1)/2)-(sum-duplicate);
        return {duplicate, missing};
    }
};

