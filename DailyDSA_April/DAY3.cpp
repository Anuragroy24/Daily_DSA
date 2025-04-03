class Solution {
    public:
        int minimumDifference(vector<int>& nums) {
            int n = nums.size()/2;
            int totalSum = 0;
            for(int i = 0; i < n; i++){
                totalSum += nums[i];
            }
    
            int sum = totalSum/2;
    
            vector<bool> prev(sum+1, false), cur(sum+1, false);
            
            prev[0] = cur[0] = true;
             if (nums[0] <= sum) {
                prev[nums[0]] = true;
            }
            
            for(int i = 1; i < n; i++){
                for(int target = 1; target <= sum; target++){
                     bool Npick = prev[target];
                      bool pick = false;
                    if (target >= nums[i]) { 
                        pick =prev[target - nums[i]];
                    }
                     cur[target] = Npick || pick;
                }
                prev = cur;
            }
    
            int mini = 1e8;
            for(int s1 = 0; s1 <= totalSum/2; s1++){
                if(prev[s1] == true){
                mini = min(mini, abs((totalSum - s1)- s1));
                }
            }
            return mini;
        }
    };