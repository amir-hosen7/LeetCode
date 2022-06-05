class Solution {
public:
    int reverse(int x) {
        bool flag=0;
        if(x<0){
            flag=1;
        }
        x=abs(x);
        long long rev=0;
        while(x>0){
            rev=rev*10+x%10;
            x/=10;
        }
        if(flag==1){rev=-rev;}
        if(rev>INT_MAX or rev<INT_MIN){
            return 0;
            }
        return rev;
    }
};