class Solution {
public:
    /*
        t -> subsequence of -> s
        Input: s = "caaat", t = "cat"
        its kind of the same as is subsequence ad we just add the rest
    */
    int appendCharacters(string s, string t) {
        int j = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == t[j]) {
                ++j;
            }
        }
        return t.size() - j ;
    }
};