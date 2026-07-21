class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxi = 0;

        
        while (r<prices.size()) {
            int profit = prices[r] - prices[l];
            if (profit > 0) {
                maxi = max(profit, maxi);
            } else {
                l = r;
                
            }
            r++;
        }
        return maxi;
    }
};
