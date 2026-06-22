class Solution {
public:
    long long minHrCnt(vector<int>& nums, int mid) {
        long long cnt = 0;
        for(int it : nums) {
            
            cnt += (it + mid - 1LL) / mid; 
        }
        return cnt; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low<=high){
            int mid = (low + high)/2;
            int minHr = minHrCnt(piles,mid);
            if(minHr > h){
                low = mid + 1;

            }else{
                ans = mid;
                high = mid -1;
            }
        }
        return ans;
    }
};
