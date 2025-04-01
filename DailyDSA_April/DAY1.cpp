class Solution {
    // private:
    // bool isTarget(int ind, vector<int>& arr, int sum, vector<vector<int>>& dp){
    //     if(arr[ind] == sum) return true;
    //      if (ind < 0) return false;
         
    //      if(dp[ind][sum] != -1) return dp[ind][sum];
        
    //     bool Npick = isTarget(ind-1, arr, sum, dp);
    //     bool pick =  isTarget(ind-1, arr, sum-arr[ind], dp);
    //     return dp[ind][sum] = Npick || pick;
    // }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(sum+1, false));
        // return isTarget(n-1, arr, sum, dp);
        vector<bool> prev(sum+1, false), cur(sum+1, false);
        // for(int i = 0; i < n; i++){
        //   dp[i][0] = true;
        // }
        prev[0] = cur[0] = true;
         if (arr[0] <= sum) {
            prev[arr[0]] = true;
        }
        
        for(int i = 1; i < n; i++){
            for(int target = 1; target <= sum; target++){
                 bool Npick = prev[target];
                 bool pick = false;
                if (target >= arr[i]) { 
                    pick =prev[target - arr[i]];
                }
                 cur[target] = Npick || pick;
            }
            prev = cur;
        }
        return prev[sum];
    }
};