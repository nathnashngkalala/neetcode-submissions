class Solution {
public:
    /*
        so the most frequent substring right now usually is your answer
        we can go trough the string and count everytime we find a
        max freq characters that is our substring
        everytime its not valid we shrink our counter
        the substring is invalid iff the substring
        substringlength > k - max_freq
    */
    int characterReplacement(string s, int k) {
        int res = 0;
        int l = 0;
        int n = s.size();
        int max_freq = 0;
        vector<int> counter(26, 0);
        for(int r = 0; r < n; ++r) {
            counter[s[r] - 'A']++;
            max_freq = max(max_freq, counter[s[r] - 'A']);
            while((r - l + 1) - max_freq > k) {
                counter[s[l] - 'A']--;
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
