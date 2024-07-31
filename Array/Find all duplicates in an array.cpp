Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or
twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 
Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.


* we can use the array itself to mark occurance of elements. when an element is found which is already marked, we add it to
  ans.
* marking --: we mark 1 at index 0, 2 at index 1.... (x at index x-1)
* this marking works because array range is [1,n]
* how to mark --: we make nums[x-1] = nums[x-1]*(-1) { make it negative }.
* we cant just mark by making it 0 or -1, because the value at nums[x-1] is needed during further traversal.
* now since the values may become negative at each iteration , we take absolute values of current element.


'Intuition'
- To solve this problem in O(n) time and constant extra space, we can utilize the fact that all integers in the array are in 
   the range [1, n] and each integer appears once or twice.
- We can iterate through the array and use each element as an index to mark the corresponding element as negative.
- If we encounter an element that is already negative, it means we have seen it before and its a duplicate.

'Approach'
- Initialize an empty vector ans to store the duplicates.
- Iterate through the array nums.
- For each element nums[i], take its absolute value x.
- Check if nums[x-1] is negative.
- If it is, then x is a duplicate, so add it to ans.
- Otherwise, mark nums[x-1] as negative.
- Return ans.


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int x = abs(nums[i]);
            if(nums[x - 1] < 0){
                ans.push_back(x);
            }
            nums[x - 1] *= -1;
        }
        return ans;
    }
};