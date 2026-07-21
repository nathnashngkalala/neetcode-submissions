class Solution {
public:
    /*
        Can be solved using 3 pointers
        when we see 0 move left, 2 move right mid skip
        its constant space and linear
    */
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, mid = 0, r = n - 1;
        while(mid <= r) {
            if(nums[mid] == 0) {
                swap(nums[l++], nums[mid++]);
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[r--]);
            } else {
                ++mid;
            }
        }
    }
};