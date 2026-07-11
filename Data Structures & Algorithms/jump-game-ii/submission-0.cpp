class Solution {
public:
    int jump(vector<int>& nums) {
        int currPos = 0;
        int maxInd = 0;
        int jumps = 0;
        for(int i = 0;i<nums.size();i++){
            if(i>currPos){
                jumps++;
                currPos = maxInd;
            }
            maxInd = max(maxInd,nums[i]+i);
        }
        return jumps;
    }
};
