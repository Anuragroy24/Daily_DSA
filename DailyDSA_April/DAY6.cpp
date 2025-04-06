class Solution {
    private:
private:
    int minimumPath(int row, int col, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(row == n-1) return triangle[row][col];

        if(dp[row][col] != -1) return dp[row][col];

        int down = triangle[row][col] + minimumPath(row+1, col, n, triangle, dp);
        int diagonal = triangle[row][col] + minimumPath(row+1, col+1, n, triangle, dp);
        return dp[row][col] = min(down, diagonal);
    }    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minimumPath(0, 0, n, triangle, dp);
        
    }
};