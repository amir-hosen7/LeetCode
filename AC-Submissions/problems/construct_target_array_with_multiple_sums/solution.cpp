class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        long long sum = 0;
        priority_queue<int> pq; //it is a max heap
        for(int num:target)
        {
            sum += num;
            pq.push(num);
        }
        
        while(pq.top() != 1)
        {             
            int maxItem = pq.top();
            pq.pop();
            
            sum -= maxItem;
            if(sum > maxItem || sum < 1)
                return false;
            
            int preItem = maxItem % sum;
            if(preItem > 0)
            {
                sum += preItem;
                pq.push(preItem);
            }
            else
                pq.push(sum);
            
        }
                
        return true;
    }
};