class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorr1 = 0;
        int xorr2 = 0;
        for(int i = 0;i<nums.size();i++){
            xorr1^=i;
            xorr2^=nums[i];
        }
        xorr1^=nums.size();
        int xorr = xorr1 ^ xorr2;
        return xorr;
    }
};
