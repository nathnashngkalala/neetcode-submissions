class Solution {
public:
    /*
        have two strings s & t, return true if 
        2 strings are anagrams o/w return false 
        just count....
    */
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char , int> counter;
        for(char c : s) {
            ++counter[c];
        }
        for(char c : t) {
            --counter[c];
            if(counter[c] < 0) {
                return false;
            }
        }        
        return true;
    }
};
