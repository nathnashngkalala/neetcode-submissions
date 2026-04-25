class Solution {
public:
    /*
        Have an array of + integers hegiht
        return max area of water can be trapped
        we use pointers at the end
        to get max area we move the smaller height, we assume 
        height and widht also 
        I miss understood so for each l and r we see if we can trap water or not

    */
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while(l < r) {
            if(leftMax < rightMax) {
                ++l;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                --r;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};
