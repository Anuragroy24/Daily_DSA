class Solution {
    // private:
    //     int paths(int n, vector<vector<int>>& matrix, int row, int col,
    //     vector<vector<int>>& dp){
    //         if(col < 0 || col > n-1) return 1e8;
    //         if(row == 0) return matrix[row][col];

    //         if(dp[row][col] != -1) return dp[row][col];

    //         int middle = matrix[row][col] + paths(n, matrix, row-1, col, dp);
    //         int left = matrix[row][col] + paths(n, matrix, row-1, col-1, dp);
    //         int right = matrix[row][col] + paths(n, matrix, row-1, col+1,
    //         dp);

    //         return dp[row][col] = min({left, middle, right});

    //     }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int middle = matrix[i][j] + dp[i - 1][j];
                int left = matrix[i][j];
                if(j-1 >= 0) left+= dp[i - 1][j - 1];
                else left += 1e8;
                int right = matrix[i][j]; 
                if(j+1 < n) right += dp[i - 1][j + 1];
                else right += 1e8;
                dp[i][j] = min({middle, left, right});
            }
        }

        int mini = 1e8;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[n-1][j]);
        }

        return mini;
    }
};