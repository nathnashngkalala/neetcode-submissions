class Solution {
public:
    /*
        have s and t, return true if s is subsequence of t
        we can use two pointer and if s at end true
    */
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {
                ++i;
            }
            ++j;
        }
        return i >= s.size();
    }
};