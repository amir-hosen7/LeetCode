class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n=v.size(), carry=1, tot;
        for(int i=n-1; i>=0; i--){
            tot=v[i]+carry;
            carry=tot/10;
            v[i]=tot%10;
        }
        if(carry>0){
            v.insert(v.begin(), carry);
        }
        return v;
    }
};