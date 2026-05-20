class Solution {
public:
    /*
        maybe we can encode it with 
        {size} + # + {word}
    */
    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            res = res + (to_string(s.size()) + "#" + s);
        }
        return res;
    }

    vector<string> decode(string s) {
        int size = 0;
        vector<string> res;
        string curr = "";
        // cout << s << endl;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(isdigit(c)) {
                size = (size * 10) + (c - '0');
            } else if (c == '#') {
                // cout << i << " " << size << endl;
                res.push_back(s.substr(i + 1, size));
                i += size;
                size = 0;
            }
        }
        return res;
    }
};
