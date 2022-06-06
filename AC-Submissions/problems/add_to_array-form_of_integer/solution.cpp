class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size(), carry=0, tot, i;
        for(i=n-1; i>=0 and k>0; i--){
            tot=(num[i]+k%10+carry);
            carry=tot/10;
            num[i]=tot%10;
            k/=10;
        }
        while(carry>0 and i>=0){
            tot=num[i]+carry;
            carry=tot/10;
            num[i]=tot%10;
            i--;
        }
        while(k>0){
            tot=k%10+carry;
            //cout<<tot<<" "<<k<<" tot\n";
            carry=tot/10;
            num.insert(num.begin(), tot%10);
            k/=10;
            //cout<<k<<" k\n";
        }
        if(carry>0){
            num.insert(num.begin(), carry);
        }
        return num;
    }
};