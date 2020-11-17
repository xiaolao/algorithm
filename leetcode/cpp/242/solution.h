// Given two strings s and t , write a function to determine if t is an anagram of s.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.

// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?
#include <algorithm>
#include <string>
#include <functional>
#include <unordered_map>

using std::sort;
using std::string;
using std::unordered_map;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
            map[s[i]]++, map[t[i]]--;

        for (auto it : map)
            if (it.second != 0) return false;
        
        return true;
    }

    bool isAnagram2(string s, string t)  {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram3(string s, string t) {
        if (s.size() != t.size()) return false;

        int hash[26] = {0}; // 初始化维度为26的数组
        for (int i = 0; i < s.size(); i++)
            hash[s[i]-'a']++, hash[t[i]-'a']--;

        for (int i = 0; i < 26; i++)
            if (hash[i] != 0) return false;

        return true;
    }

};
