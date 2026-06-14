class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int last = nums[0];
        int maxi = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]== last +1){
                cnt++;
                maxi = max(cnt,maxi);
            }
            else if(nums[i]==last){
                continue;
            }else {cnt=1;}
            last = nums[i];
        }
        return maxi;
    }
};
