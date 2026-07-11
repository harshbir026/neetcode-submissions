class Solution {
   public:
    bool helper(vector<int>& hand, int k, int i) {
        int val = hand[i];
        hand[i] = -1;
        k--;
        i++;
        while (k > 0 && i < hand.size()) {
            if (hand[i] == val + 1) {
                val += 1;
                hand[i] = -1;

                k--;
            }
            i++;
        }
        return k == 0;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if ((hand.size() % groupSize) != 0) return false;
        sort(hand.begin(), hand.end());
        for (int i = 0; i < hand.size(); i++) {
            if (hand[i] >= 0) {
                if (!helper(hand, groupSize, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};
