class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        bool x = false;
        bool y = false;
        bool z = false;

        for(auto t : triplets){
            x |= (t[0]==target[0] && t[1]<=target[1] && t[2] <= target[2]); // x = x |(or) condition i.e.
            y |= (t[0]<=target[0] && t[1]==target[1] && t[2] <= target[2]);// x = false | y(false/true)
            z |= (t[0]<=target[0] && t[1]<=target[1] && t[2] == target[2]); //if y = true then x true else false
            if(x && y && z) return true;
        }
        return false;
    }
};
