class Solution {
    private:
        int paths(int row, int col1, int col2, vector<vector<int>>& grid, int n, int m,  vector<vector<vector<int>>>& dp){
            if(col1 < 0 || col1 > m-1 || col2 < 0 || col2 > m-1) return -1e8;
            if(row == n-1){
                if(col1 == col2) return grid[row][col1];
                else return grid[row][col1] + grid[row][col2];
            }
    
            // int dlCol[] = {-1, 0, 1};
    
            if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
           
    
            int maxi = 0;
    
            for(int dl = -1; dl < 2; dl++){
                for(int dl2 = -1; dl2 < 2; dl2++){
                    if(col1 == col2) maxi = max(maxi, grid[row][col1] + paths(row+1, col1+dl, col2+dl2, grid, n, m, dp));
                    else maxi = max(maxi, grid[row][col1] + grid[row][col2] + paths(row+1, col1+dl, col2+dl2, grid, n ,m, dp));
    
                }
            }
            return dp[row][col1][col2] = maxi;
    
        }    
    public:
        int cherryPickup(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
    
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    
            return paths(0, 0, m-1, grid, n, m, dp);
    
            
        }
    };