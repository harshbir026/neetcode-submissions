class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(),nums.end());
        int longestStreak = 0;
        for(auto num : numSet){
            if(numSet.find(num-1)==numSet.end()){
                int currNum = num;
                int currStreak = 1;
                while(numSet.find(currNum +1)!= numSet.end()){
                    currNum +=1;
                    currStreak+=1;
                }
                longestStreak = max(longestStreak,currStreak);
            }
        }
        return longestStreak;
    }
};
