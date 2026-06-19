class Solution {
public:
    /*
        must be in place, if not its pretty easy right 
        you can put 
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int curr = m + n - 1;
        int l = m - 1, r = n - 1;
        while(l >= 0 && r >= 0) {
            if(nums1[l] >= nums2[r]) {
                nums1[curr--] = nums1[l--];
            } else {
                nums1[curr--] = nums2[r--];
            }
        }
        while(l >= 0) {
            nums1[curr--] = nums1[l--];
        }
        while(r >= 0) {
            nums1[curr--] = nums2[r--];
        }
    }
};