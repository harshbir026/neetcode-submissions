class Solution {
public:
    int bs(vector<int>& nums,int l,int r,int k){
        if(l>r) return -1;
        
        int mid  = (l+r)/2;
        if(nums[mid] == k){
            return mid;
        } else if(nums[mid]>k){
            return bs(nums,l,mid-1,k);
        }else{
            return bs(nums,mid+1,r,k);
        }
    }
    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }
};
