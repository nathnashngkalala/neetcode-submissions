class Solution {
public:
    /*
        have array strings strs, group anagram together
        anagram -> contains the same chars as other characters
        make a key for each with count of chars
        and they we make a list
        O(n * m)
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        for(int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            vector<int> counter (26,0);
            for(char c : s ) {
                counter[c - 'a']++;
            }
            string key = "";
            for(int j = 0; j < counter.size(); ++j) {
                key += (to_string(counter[j]) + "#");
            }
            anagramMap[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto it : anagramMap) {
            res.push_back(it.second);
        }
        return res;
    }
};
