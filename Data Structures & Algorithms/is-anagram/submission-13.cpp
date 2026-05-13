class Solution {
public:
    /*
        string contains exact same chars as the other string but diff order
        sort if n log n time but constant space
        we can do linear time with linear space, but since we have 26 chars its actually
        O(26)
    */
    bool isAnagram(string s, string t) {
        if(s.size() > t.size()) {
            string temp = s;
            s = t;
            t = temp;
        }
        vector<int> counter(26, 0);
        for(char c : s) {
            ++counter[c - 'a'];
        }
        for(char c : t) {
            --counter[c - 'a'];
            if(counter[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
