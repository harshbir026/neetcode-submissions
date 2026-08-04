class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totSum = accumulate(nums.begin(),nums.end(),0);
        int target = totSum/2;
        if((totSum%2)!=0) return false;
        bitset<5001>st;
        st[0] = 1;
        for(int num : nums){
            st |= (st<<num);
        }
        return st[target] ;
    }
};
