class Solution {
public:
    /*
        have string s return true if palindrome.
    */
    bool isAlphabetOrDigit(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.size() -1;
        while(l < r) {
            while(l < r && !isAlphabetOrDigit(s[l])) {
                ++l;
            }
            while(r > l && !isAlphabetOrDigit(s[r])) {
                --r;
            }
            if(tolower(s[l++]) != tolower(s[r--])){
                return false;
            }
        }   
        return true;     
    }
};
