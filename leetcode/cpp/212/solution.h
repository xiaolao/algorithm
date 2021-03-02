// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

//  

// Example 1:


// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:


// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
//  

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.


#include <string>
#include <vector>
#include <functional>

using std::string;
using std::vector;
using std::function;


class TrieNode {
public:
    string word;
    TrieNode* next[26];

    TrieNode() {
        word = "";
        memset(next, 0, sizeof(next));
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size(), col = board[0].size();

        // 构建Trie树
        TrieNode* root = new TrieNode();
        for (string word : words) {
            TrieNode* cur = root;
            for (char c : word) {
                if (cur->next[c-'a'] == nullptr) {
                    cur->next[c-'a'] = new TrieNode();
                }
                cur = cur->next[c-'a'];
            }
            cur->word = word;
        }

        vector<string> result;

        function<void(int, int, TrieNode* node)> dfs = [&](int i, int j, TrieNode* node) {
            char c = board[i][j];  // 
            if (c == '.' || node->next[c-'a'] == nullptr) return;

            node = node->next[c-'a'];
            if (node->word != "") {
                result.push_back(node->word);
                node->word = "";
            }

            board[i][j] = '.';
            if (i>0) dfs(i-1, j, node);
            if (i<row-1) dfs(i+1, j, node);
            if (j>0) dfs(i, j-1, node);
            if (j<col-1) dfs(i, j+1, node);
            board[i][j] = c;
        };

        for (int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                dfs(i, j, root);
            }
        }
        return result;
    }
};
