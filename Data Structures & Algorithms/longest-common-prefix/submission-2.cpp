class Solution {
public:
    /*
        string[], return longest common prefix
        brute force try each pair is n^2 
        actually it alkways have to be n * m
    */
    string getCommonPrefix(const string& a, const string& b) {
        int i = 0, j = 0;
        int m = a.size(), n = b.size();
        while(i < m && j < n) {
            if(a[i] == b[j]) {
                ++i;
                ++j;
            } else {
                break;
            } 
        }
        return a.substr(0, i);
    }
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        for(int i = 1; i < strs.size(); ++i) {
            string other = strs[i];
            common = getCommonPrefix(common, other);
        }
        return common;
    }
};