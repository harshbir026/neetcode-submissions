class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(),nums.end());
        int longestStreak = 0;
        for(auto num : numSet){
            if(numSet.find(num-1)==numSet.end()){
                
                int len = 1;
                while(numSet.find(num +len)!= numSet.end()){
                    len++;
                    
                }
                longestStreak = max(longestStreak,len);
            }
        }
        return longestStreak;
    }
};
