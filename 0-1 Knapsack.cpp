class Solution {
  public:
  
    int dp[1001][1001];
  
    int solve(int wt[], int val[], int W, int n){
        if(n == 0 || W == 0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        if(wt[n-1] <= W){
            return dp[n][W] = max(
                val[n-1] + solve(wt, val, W - wt[n-1], n-1),
                solve(wt, val, W, n-1)
            );
        }
        else{
            return dp[n][W] = solve(wt, val, W, n-1);
        }
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        memset(dp, -1, sizeof(dp));
        int n = val.size();
        
        return solve(wt.data(), val.data(), W, n);
    }
};
