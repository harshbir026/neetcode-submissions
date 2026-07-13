class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        bool x = false;
        bool y = false;
        bool z = false;

        for(auto t : triplets){
            x |= (t[0]==target[0] && t[1]<=target[1] && t[2] <= target[2]);
            y |= (t[0]<=target[0] && t[1]==target[1] && t[2] <= target[2]);
            z |= (t[0]<=target[0] && t[1]<=target[1] && t[2] == target[2]);
            if(x && y && z) return true;
        }
        return false;
    }
};
