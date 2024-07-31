Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Intuition
The Two Sum problem asks us to find two numbers in an array that sum up to a given target value. We need to return the 
indices of these two numbers.

Approach
-- One brute force approach is to consider every pair of elements and check if their sum equals the target. 
-- This can be done using nested loops, where the outer loop iterates from the first element to the second-to-last element,
   and the inner loop iterates from the next element to the last element. However, this approach has a time complexity of O(n^2).
-- A more efficient approach is to use a hash table (unordered_map in C++). We can iterate through the array once, 
   and for each element, check if the target minus the current element exists in the hash table. If it does, we have found 
   a valid pair of numbers. If not, we add the current element to the hash table.

Approach using a hash table:

1. Create an empty hash table to store elements and their indices.
2. Iterate through the array from left to right.
3. For each element nums[i], calculate the complement by subtracting it from the target: complement = target - nums[i].
4. Check if the complement exists in the hash table. If it does, we have found a solution.
5. If the complement does not exist in the hash table, add the current element nums[i] to the hash table with its index as
   the value.
6. Repeat steps 3-5 until we find a solution or reach the end of the array.
7. If no solution is found, return an empty array or an appropriate indicator.
8. This approach has a time complexity of O(n) since hash table lookups take constant time on average. It allows us to solve 
   the Two Sum problem efficiently by making just one pass through the array.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(mpp.find(target - nums[i]) != mpp.end()){
                ans.push_back(mpp[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mpp[nums[i]] = i;
        }
        //dummy return statement
        return ans;
    }
};