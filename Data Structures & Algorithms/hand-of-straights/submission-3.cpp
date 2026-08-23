class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Step 1: Quick check
        if (hand.size() % groupSize != 0) return false;
        
        // Step 2: Build a frequency map
        // map automatically keeps the keys (card values) sorted!
        map<int, int> counts;
        for (int card : hand) {
            counts[card]++;
        }
        
        // Step 3: Try to form groups
        for (auto it = counts.begin(); it != counts.end(); it++) {
            int card = it->first;
            int count = it->second;
            
            // If this card is still available, we must start a group here
            if (count > 0) {
                // Try to build a consecutive group of 'groupSize'
                for (int i = 0; i < groupSize; i++) {
                    // If the required consecutive card doesn't have enough copies, it fails
                    if (counts[card + i] < count) {
                        return false;
                    }
                    // Deduct the cards we just used
                    counts[card + i] -= count;
                }
            }
        }
        
        return true;
    }
};