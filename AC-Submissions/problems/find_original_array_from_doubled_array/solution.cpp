class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int siz=changed.size();
        vector<int> original;
        if(siz%2) return original;
        sort(changed.begin(), changed.end());
        unordered_map<int, int> mark;
        for(int i=0; i<siz; i++){
            mark[changed[i]]++;
        }
        for(int i=0; i<siz; i++){
            if(changed[i]==0){
                if(mark[0]>=2){
                    original.push_back(0);
                    mark[0]-=2;
                }
            }
            else if(mark[changed[i]*2]>=1 and mark[changed[i]]>=1){
                mark[changed[i]*2]--;
                mark[changed[i]]--;
                original.push_back(changed[i]);
            }
        }
        if(original.size()!=siz/2){
            original.clear();
            return original;
        }
        return original;
    }
};

