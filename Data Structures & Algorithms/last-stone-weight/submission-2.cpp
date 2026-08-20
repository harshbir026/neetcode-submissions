class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i : stones){
            pq.push(i);
        }
        while(pq.size()>1){
            int top = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            if(top2==top){
                if(pq.empty()){
                    break;
                }
            }
            if(top>top2){
                pq.push(top-top2);
            }
            
            
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
