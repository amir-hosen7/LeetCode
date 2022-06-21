class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size(), i, diff, sum=0;
        priority_queue<int, vector<int>, greater<int>>PQ;
        for(i=0; i<(n-1); i++){
            diff=heights[i+1]-heights[i];
            if(diff<=0){
                continue;
            }
            PQ.push(diff);
            if(PQ.size()>ladders){
                sum+=PQ.top();
                PQ.pop();
            }
            if(sum>bricks){
                break;
            }
        }
        return i;
    }
};