class Solution {
public:
    /*
        have int[] nums
        return output[] where [i] is product of all elements 
        except nums[i]
        product of i is esentaill product of whole array/ nums[i]
        Input: nums = [1,2,4,6]
        pre = [1,2,8,48]
        post = [48,48,24,6]
        48 is product of whole array

        Input: nums = [-1,0,1,2,3]
        0 is product of whole array
        thig is when 0 is there 0/0 -> is not valid
        so we kind of have to have two instances where 0 is not included
        prefix -> products before i
        postfix -> product after i
        output[i] = prefix[i] * postfix[i]
        pre = [-1,0,0,0,0]
        post = [0,0,6,6,3]
        edge case is i = 0 and i = n -1
        [0] -> output[i] = postfix[1]
        [n-1]-> output[i] = prefix[i]
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums;
        }
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] * nums[i];
        }
        vector<int> postfix(n);
        postfix[n-1] = nums[n- 1];
        for(int i = n - 2; i >= 0; --i) {
            postfix[i] = postfix[i + 1] * nums[i];
        }
        vector<int> res(n);
        res[0] = postfix[1];
        res[n-1] = prefix[n-2];
        for(int i = 1; i < n- 1; ++i) {
            res[i] = prefix[i - 1] * postfix[i + 1];
        }   
        return res;
    }
};
