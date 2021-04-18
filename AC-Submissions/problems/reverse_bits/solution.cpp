class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
       for(int i=31,idx=0; i>=0; i--,idx++){
           if((n&(1<<idx))>0){
               res+=(1<<i);
           }
       }
       return res;
    }
};