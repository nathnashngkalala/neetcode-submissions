class Solution {
public:
    /*
        you got int[] 
        return [] where at index i is product of all elements except nums[i]
        using prefix product and postfix product
        [1,2,0,6]
        [0,0,12,0]
        [1,2,0,0] -> for i its pre[i-1] * post[i + 1]
        [0,0,0,6]

        [1,2,4,6]
        [48,24,12,8]
        [1,2,8,48] -> for i its pre[i-1] * post[i + 1] works for between
        [48,48,24,6]
        base case of [0] and [n -1] 
        res[0] -> post[0]
        res[n -1] -> pre[n - 1]
        Overall Complexity: O(n)
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProd(n); preProd[0] = nums[0];
        for(int i = 1; i < n; ++i) {
            preProd[i] = preProd[i - 1] * nums[i];
        }
        vector<int> postProd(n); postProd[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            postProd[i] = postProd[i + 1] * nums[i];
        }
        vector<int> res(n);
        res[0] = postProd[1];
        res[n -1] = preProd[n - 2];
        for(int i = 1; i < n - 1; ++i) {
            res[i] = preProd[i - 1] * postProd[i + 1];
        }
        return res;
    }
};
