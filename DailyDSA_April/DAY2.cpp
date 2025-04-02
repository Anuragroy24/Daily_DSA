class Solution {
    private:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum+1, false), cur(sum+1, false);
        
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

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }

        if(totalSum % 2) return false;
        int target = totalSum/2;
         return isSubsetSum(nums, target);
    }
};