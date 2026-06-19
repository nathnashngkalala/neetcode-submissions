class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        bool isWord1 = true;
        int l = 0, r = 0;
        while(l < word1.size() && r < word2.size()) {
            res += (isWord1) ? word1[l++] : word2[r++];
            isWord1 = !isWord1;
        }
        while(l < word1.size()){
            res += word1[l++];
        }
        while(r < word2.size()){
            res += word2[r++];
        }
        return res;
    }
};