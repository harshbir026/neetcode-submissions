#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Your clean Node structure, adapted for Word Search II
struct Node {
    Node* links[26] = {nullptr};
    string word = ""; // Replaces bool flag. Stores the completed word.

    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
};

// 2. Your clean Trie class
class Trie {
public:
    Node* root;

    Trie() { 
        root = new Node(); 
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->word = word; // Store the actual word at the end node
    }
};

// 3. The DFS Solution
class Solution {
private:
    void dfs(int r, int c, vector<vector<char>>& board, Node* node, vector<string>& result) {
        // 1. BOUNDARY CHECK FIRST (fixes the ASan crash)
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
            return;
        }

        // 2. Safe to read the character
        char ch = board[r][c];

        // 3. Check if cell is visited ('#') or if the Trie path doesn't exist
        if (ch == '#' || !node->containsKey(ch)) {
            return;
        }

        // 4. Move down the Trie to the next letter
        node = node->get(ch);

        // 5. Check if this node marks the end of a word
        if (node->word != "") {
            result.push_back(node->word); // Found a word!
            node->word = ""; // Erase it from the Trie so we don't find it twice
        }

        // 6. Mark current cell as visited
        board[r][c] = '#';

        // 7. Explore all 4 directions
        dfs(r + 1, c, board, node, result); // Down
        dfs(r - 1, c, board, node, result); // Up
        dfs(r, c + 1, board, node, result); // Right
        dfs(r, c - 1, board, node, result); // Left

        // 8. Backtrack: Restore the cell for other DFS paths to use
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        
        // Insert all target words into the Trie
        for (string word : words) {
            trie.insert(word);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        // Start a DFS path from every single cell on the board
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(r, c, board, trie.root, result);
            }
        }

        return result;
    }
};