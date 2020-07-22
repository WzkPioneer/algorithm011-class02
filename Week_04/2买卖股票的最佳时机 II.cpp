class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        // 第二维的 0 表示当前持有的现金（cash）， 1 表示当前持有的股票（stock）   
        vector<vector<int>> dp(n, vector<int> (2));
        // 初始化
        dp[0][0] = 0;
        dp[0][1] = -prices[0];  // 买入的股票
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], prices[i] + dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
