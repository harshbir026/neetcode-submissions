struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;
    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class WordDictionary {
    Node* root;

public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        // Kick off the recursive search starting at index 0 and the root node
        return searchHelper(word, 0, root);
    }

private:
    bool searchHelper(const string& word, int index, Node* node) {
        // Base case: We reached the end of the word. 
        // Check if the current node is actually marked as the end of a word.
        if (index == word.length()) {
            return node->isEnd();
        }

        char ch = word[index];

        if (ch == '.') {
            // WILDCARD LOGIC: Try all 26 possible paths
            for (int i = 0; i < 26; i++) {
                if (node->links[i] != nullptr) {
                    // If ANY of the paths return true, the whole search is true!
                    if (searchHelper(word, index + 1, node->links[i])) {
                        return true;
                    }
                }
            }
            // If we checked every existing child and none matched, return false
            return false;
        } 
        else {
            // NORMAL LETTER LOGIC: Just check the specific path
            if (!node->containsKey(ch)) {
                return false;
            }
            return searchHelper(word, index + 1, node->get(ch));
        }
    }
};