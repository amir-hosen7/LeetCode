class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN and divisor==1){
            return INT_MIN;
        }
        if(dividend==INT_MIN and divisor==-1){
            return INT_MAX;
        }
        long long up=abs(dividend), down=abs(divisor);
        int res=0;
        while(down<=up){
            long long curr=1,tot=down;
            while(tot<=(up-tot)){
                tot+=tot, curr+=curr;
            }
            up-=tot;
            res+=curr;
        }
        if((dividend<0 and divisor>0) or (divisor<0 and dividend>0)){
            return -res;
        }
        return res;
    }
};