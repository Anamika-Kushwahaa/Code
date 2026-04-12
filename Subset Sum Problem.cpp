class Solution {
  public:
    bool solve(vector<int>& arr, int n, int sum,vector<vector<int>> & memo){
        if(sum==0) return 1;
        if(n<=0) return 0;
        if(memo[n][sum] != -1) {
            return memo[n][sum];
        }
        
        if(arr[n-1]>sum){
            return memo[n][sum]= solve(arr,n-1,sum,memo);
        }
        else{
            return memo[n][sum]= solve(arr,n-1,sum,memo)||
                                 solve(arr,n-1,sum-arr[n-1],memo);
        }
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n= arr.size();
        vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
        return solve(arr,n,sum,memo);
        
    }
};
