class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit;
    KthLargest(int k, vector<int>& nums) {
        limit = k;
        for(int i = 0;i<nums.size();i++){
            add(nums[i]);
        }
    }

    int add(int val) {
        pq.push(val);
        if(pq.size()>limit){
            pq.pop();
        }
        return pq.top();
    }
};
