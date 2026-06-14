class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod1(n,1);
        vector<int> prod2(n,1);
        for(int i = 1;i<n;i++){
            prod1[i] = prod1[i-1]*nums[i-1];

    }
        for(int i = n-2;i>=0;i--){
            prod2[i] = prod2[i+1]*nums[i+1];
            
        }
        vector<int> prod(n);
        for(int i = 0;i<n;i++){
            prod[i] = prod1[i]*prod2[i];
        }
        return prod;
    }
};
