Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such 
that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 
Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109


* we add another for loop outside the three sum problem.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i] == nums[i-1]){            // skipping possible duplicate quadruples
                continue;
            }
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j] == nums[j-1]){      // skipping possible duplicate quadruples
                    continue;
                }
                int l = j+1, r = n-1;
                while(l < r){
                    long long sum = nums[i] ;
                    sum += nums[j];
                    sum += nums[l];
                    sum += nums[r];
                    if(sum == target){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        ans.push_back(temp);
                        do{
                            l++;
                        }
                        while(l < n && nums[l] == nums[l-1]);   // skipping duplicates
                        do{
                            r--;
                        }
                        while(r >= j+1 && nums[r] == nums[r+1]);  // skipping duplicates
                    }
                    else if(sum > target){
                        r--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};