class Solution {
public:
    /*
        you have string s, only uppercase
        and integer k, you can choose k to replace (<= k)
        return longest substring which one distinct character
        you can keep the most frequent char and use that
        its kind of like a greedy algorithm but 
        having the most frequent count gives you exactly the longest substring
        AAABABB, k = 1
        AAAAA -> 4
        AAAAAB -> invalid -> B
        BBBB -> 4
        so once a substring is invalid (substr.len - mostFreq > k) 
        you would shrink I would say
    */
    int characterReplacement(string s, int k) {
        int l = 0;
        int n = s.size();
        vector<int> counter (26,0);
        int mostFreq = 0;
        int res = 0;
        for(int r = 0; r < n; ++r) {
            ++counter[s[r] - 'A'];
            mostFreq = max(mostFreq, counter[s[r] - 'A']);
            while((r - l + 1) - mostFreq > k) {
                --counter[s[l] - 'A'];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
