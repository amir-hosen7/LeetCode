class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp(m);
        for(int i=0; i<m; i++){
            temp[i]=nums1[i];
        }
        int i=0, j=0, idx=0;
        while(i<m and j<n){
            if(temp[i]>nums2[j]){
                nums1[idx++]=nums2[j++];
            }
            else{
                nums1[idx++]=temp[i++];
            }
        }
        while(i<m){
            nums1[idx++]=temp[i++];
        }
        while(j<n){
            nums1[idx++]=nums2[j++];
        }
    }
};