class Solution {
public:
    bool canMeasureWater(int a, int b, int c) {
        if(c>(a+b)){return 0;}
        int gcd=__gcd(a,b);
        if(gcd!=1){
            if(c%gcd==0){return 1;}
            return 0;
        }
        return 1;
    }
};