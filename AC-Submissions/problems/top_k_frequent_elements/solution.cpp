class Solution {
public:
    struct cmp {
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++){
            cnt[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>PQ;
        for(auto i : cnt){
            PQ.push({i.first, i.second});
            if(PQ.size() > k){
                PQ.pop();
            }
        }
        int idx = k-1;
        while(!PQ.empty()){
            nums[idx--] = PQ.top().first;
            PQ.pop();
        }
        while(n > k){
            nums.pop_back();
            n--;
        }
        return nums;
    }
};
