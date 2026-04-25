class Solution {
public:
    /*
        Alice and Bob plays a game where even number of piles in a row
        piles[i] -> + # of stones
        end with most stones, total # of stones are odd -> no ties
        Alice start first each turn a player take the entire pile of stones
        begining or end 
        ture if Alice wins game
        so we can use dp where Alice can take start or end for each choice 
        base case l >= r 
        dp[i][j]
    */
    vector<vector<int>> dp;
    int target;
    bool solve(int l, int r, int turn, int curr, const vector<int>& piles) {
        if(l >= r) {
            return curr > target;
        }
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        bool a, b = false;
        if(turn == 0) {
            a = solve(l + 1, r, 1, curr + piles[l], piles);
            b = solve(l, r - 1, 1, curr + piles[r], piles);
        } else {
            a = solve(l + 1, r, 0, curr, piles);
            b = solve(l, r - 1, 0, curr, piles);
        }
        return dp[l][r] = a || b;
    }
    bool stoneGame(vector<int>& piles) {
        dp = vector<vector<int>>(piles.size(), vector<int>(piles.size(), - 1));
        return solve(0, 0, piles.size() - 1, 0, piles);
    }
};