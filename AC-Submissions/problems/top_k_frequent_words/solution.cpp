class Solution {
public:
    struct cmp {
        bool operator() (const pair<string, int> &a, const pair<string, int> &b) {
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> cnt;
        for(int i = 0; i < n; i++){
            cnt[words[i]]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp>PQ;
        for(auto i : cnt){
            PQ.push({i.first, i.second});
            if(PQ.size() > k){
                PQ.pop();
            }
        }
        int idx = k-1;
        while(!PQ.empty()){
            words[idx--] = PQ.top().first;
            PQ.pop();
        }
        while(n > k){
            words.pop_back();
            n--;
        }
        return words;
    }
};

