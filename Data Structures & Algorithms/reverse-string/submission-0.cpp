class Solution {
public:
    /*
        have array cahrs represent string
        reverse without extra memory
    */
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() -1;
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
};