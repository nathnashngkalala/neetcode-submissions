class Solution {
public:
    /*
        so there are only 3 colors we can do this
        we have pointers for each the left is for 0, right is 2
        and mid is 1
        when mid is 0 or 2 we move to appropriate place
        its like having 3 pointers bascially
        once mid > right then we are done
        mid starts at left, if its 1 then we advance it because its in place
    */
    void sortColors(vector<int>& nums) {
        int l = 0, mid = 0, r = nums.size() - 1;
        while(mid <= r) {
            if(nums[mid] == 0) {
                swap(nums[l++], nums[mid++]);
            } else if(nums[mid] == 2) {
                swap(nums[r--], nums[mid]);
            } else {
                ++mid;
            }
        }
    }
};