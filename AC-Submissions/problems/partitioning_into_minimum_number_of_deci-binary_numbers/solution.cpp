class Solution {
public:
    int minPartitions(string n) {
        int sz=n.size();
        char Max='0';
        for(int i=0; i<sz; i++){
            if(n[i]>Max){
                Max=n[i];
            }
        }
        return Max-'0';
    }
};