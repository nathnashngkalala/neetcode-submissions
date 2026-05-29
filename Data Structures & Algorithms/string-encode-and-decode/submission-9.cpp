class Solution {
public:
    /*
        we can do size + string + # for encode
        when we decode we parse the digits and then construct the substring and have
        pointer go trough the string itself
    */
    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); ++i) {
            res += to_string(strs[i].size()) + "#" + strs[i] ;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        int currLen = 0;
        while(i < s.size()) {
            if(s[i] == '#') {
                res.push_back(s.substr(i + 1, currLen));
                i = i + 1 + currLen;
                currLen = 0;
            } else {
                currLen = (10 * currLen) + (s[i] - '0');
                ++i;
            }
        }
        return res;
    }
};
