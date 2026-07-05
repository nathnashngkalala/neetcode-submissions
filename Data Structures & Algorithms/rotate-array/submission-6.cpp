class Solution {
public:
    /*
        the naive way or brute force is k * n, because we rotate and shift
        k times of n array but if we just use two pointers
        one start at 0, the other starts at n - k 
        we can swap and itterate k wont be > n impossible? 
        [1,2,3,4,5,6,7,8]
        [8,7,6,5,4,3,2,1] reverse
        and reverse the first k elements
        and reverse back the last elements remaining n - k
    */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) {
            k = k % n;
        }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};