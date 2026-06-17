class Solution {
public:
    /*
        s, return true if s is plaindrome after deleting at most one char
        so when its different and we can delete on we have two choice 
        move right or left pointer, we can just use reccursion
        because we can only delete 1, there are only 2 sub problem
        so the solution will be O(n)
    */
    int solve(int l, int r, bool isRemoveUsed, const string& s) {
        while(l < r) {
            if(s[l] == s[r]) {
                ++l;
                --r;
            } else if(!isRemoveUsed) {
                return solve(l + 1, r, true, s) || solve(l, r - 1, true, s);
            } else {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        return solve(0, n - 1, false, s);
    }
};