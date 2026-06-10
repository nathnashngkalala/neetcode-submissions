class Solution {
public:
    /*
        Have int[] nums
        return length of LONGEST CONSECUTIVE seq (diff > 1)
        so for this at i I need to know is there a smaller 
        number with diff 1 that exist and what is their longest chain and we 
        use unordered map
        Input: nums = [2,20,4,10,3,4,5]
        we look for the start and linearly goes the longest
        gunrantee lienar because each start and its itteration 
        when we add them all up its just the size of the array
    */
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> counter;
        for(int x : nums) {
            counter[x]++;
        }
        int res = 0;
        for(int x : nums) {
            if(!counter.count(x-1)) {
                int temp = x + 1;
                int curr = 1;
                while(counter.count(temp)) {
                    ++curr;
                    ++temp;
                }
                res = max(res, curr);
            }
        }
        return res;
    }
};
