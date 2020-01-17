class Solution {
public:
    string defangIPaddr(string address) {
        int l = address.size();
        string ans;
        for(int i=0; i<l; i++){
            if(address[i] == '.'){
                ans+="[.]";
            }
            else{
                ans+=address[i];
            }
        }
        return ans;
    }
};