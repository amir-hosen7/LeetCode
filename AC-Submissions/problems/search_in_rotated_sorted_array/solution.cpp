class Solution {
public:
    int solve(int L, int R, vector<int>& v, int target){
        while(L<=R){
            int mid=L+(R-L)/2;
            if(v[mid]==target){
                return mid;
            }
            if(v[L]<=v[mid]){
                if(v[L]<=target and v[mid]>target){
                    R=mid-1;
                }
                else{
                    L=mid+1;
                }
            }
            else{
                if(v[R]>=target and v[mid]<target){
                    L=mid+1;
                }
                else{
                    R=mid-1;
                }
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return solve(0, nums.size()-1, nums, target);
    }
};

