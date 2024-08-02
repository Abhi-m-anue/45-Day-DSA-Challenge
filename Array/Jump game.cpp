You are given an integer array nums. You are initially positioned at the arrays first index, and each element in the
array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.


Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105


DP Tabulation
- starts from second last index, n-2
- for each index i,checks whether any possible jump within [i+1 , i+nums[i]] can reach me to an index j where dp[j] is true 
- dp[j] is true means from j to the end of array we have a possible path.
- Thats why we initialise base case : dp[n-1] = true , because we only need to reach till n-1


    class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n,0); //dp[i] = true means through i we can reach the end
            dp[n-1] = 1;
            for(int i = n-2; i>=0; i--){
                int reach = i + nums[i];
                for(int jump = i+1; jump <= reach; jump++){
                    if(jump < n && dp[jump]){
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[0];
        }
    };

Linear space soln 
- I can also think of a solution that kinda resembles Kadane's algorithm. 
- For every index, Im checking the max reach I can have till that element, if that reach is less than the value of my 
  index, that means I can never reach this particular index and my answer should be false.

tc : O(N)
sc : O(1)

    class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            int maxSoFar = 0;
            for(int i=0; i<n; i++){
                if(nums[i] == 0 && maxSoFar <= i && ( i != n-1)){
                // i!=n-1 takes care of the case when we have 0 at the last index, so we need no more steps
                    return false;
                }
                maxSoFar = max(maxSoFar,i + nums[i]); // try jumping farthest possible 
            }
            return true;
        }
    };

