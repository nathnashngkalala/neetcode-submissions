class Solution {
public:
    /*
        have int[] prices
        you can buy then imidiately sell, on same day
        allowed to do any number of transactions
        can hold at most 1 stock
        its dp -> and the choices are
        I buy now or sell depending on state
        should be n
        if state =0 
            can buy,
            skip buy
        if state = 1
            can sell
            skip sell
    */
    vector<vector<int>> dp;
    int n;
    int solve(int i , int state, const vector<int>& prices) {
        if(i >= n) {
            return 0;
        }
        if(dp[state][i] != -1) {
            return dp[state][i];
        }
        if(state == 0) {
            int buy = solve(i + 1, 1, prices) - prices[i];
            int skip = solve(i + 1, 0, prices);
            return dp[state][i] = max(buy, skip);
        }
        int sell = solve(i + 1, 0, prices) + prices[i];
        int skip = solve(i + 1, 1, prices);
        return dp[state][i] = max(sell, skip);
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp = vector<vector<int>>(2, vector<int>(n, -1));
        return solve(0, 0, prices);
    }
};