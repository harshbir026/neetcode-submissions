class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mpp(26,0);
        for(auto it : tasks){
            mpp[it-'A']++;
        }
        priority_queue<int>pq;
        for(int i = 0;i<26;i++){
            if(mpp[i]){
                pq.push(mpp[i]);
            }
        }
        int time = 0;
        while(!pq.empty()){
            vector<int>remain;
            int cycle = n+1;
            while(cycle && !pq.empty()){
                int freq = pq.top();
                pq.pop();
                if(freq>1){
                    remain.push_back(freq-1);
                }
                time++;
                cycle--;
            }
            for(auto it : remain){
                pq.push(it);
            }
            if(pq.empty()){
                break;
            }
            time+=cycle;
            
        }
        return time;
    }
};
