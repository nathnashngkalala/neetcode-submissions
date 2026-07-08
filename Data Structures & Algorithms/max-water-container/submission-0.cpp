class Solution {
public:
    /*
        have int[] heights
        choose any two bars tha can contain most water? 
        use l < r and just compute the area
        we want to see the most right so whichever the lower between
        h[l] and [r] we move
    */
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int res = 0;
        while(l < r) {
            res = max(res, min(heights[l] , heights[r]) * (r - l));
            if(heights[l] <  heights[r]) {
                ++l;
            } else if(heights[l] >  heights[r]) {
                --r;
            } else {
                ++l;
            }
        }
        return res;
    }
};
