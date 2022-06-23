class Solution {
public:
    int scheduleCourse(vector<vector<int>>& c) {
        
        // Sort by deadline
        sort(c.begin(), c.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        // Priority Queue with less<int>, so the max element will be at the top
        priority_queue<int> pq;
        int time = 0;
        for(auto& a: c){
            // if the time we have already used + duration fits the deadline we just add it 
            if(time + a[0] <= a[1]){
                time += a[0];
                pq.push(a[0]);
            }
            // if the element we are considering is less than the top element of Priority Queue (max element), remove the top element from the queue and add the element we are currently considering
            else if(!pq.empty() && pq.top() > a[0]){
                time -= pq.top();
                pq.pop();
                pq.push(a[0]);
                time += a[0];
            }
            
            // The third case that is not written is when the element we are considering is more than the top element of PQ, so we do nothing with it.
            
            // if it was written it will be something like this
            else {
                // the only case it comes down to this "else" is when pq is empty or pq.top() is less than the duration of current element, i.e. "pq.top() < course[0]"
                
                // So since it is bigger than the max element of our queue, we don't need it.
                if(pq.empty() || pq.top() < a[0])
                    continue;
            }
            
            // As you can see the else statement does nothing, so you can remove it
            // It was written to show you the 3rd case, which is usually omitted
            // in other posts of discussion.
            
        }
        
        return pq.size();
    }
};