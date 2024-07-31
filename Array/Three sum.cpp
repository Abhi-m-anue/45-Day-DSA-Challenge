Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 
Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105



Intuition
- The problem requires finding all unique triplets in the given array that sum up to zero. 
- My first thought is to use a two-pointer technique to solve this problem efficiently. 
- The idea is to fix one element and then use two pointers, one starting from the next element and one from the end of the array,
  to find a pair that sums up to the negation of the fixed element.

Approach
- The approach is to first sort the input array.
- Then, iterate over the array and for each element, use two pointers to find a pair that sums up to the negation of the 
  current element. 
- If the sum is less than target, move the left pointer to the right to increase the sum. 
- If the sum is greater than target, move the right pointer to the left to decrease the sum. 
- If the sum is equal to zero, add the triplet to the result and move both pointers.


note :-- we can see that inside the for loop we have a two sum problem. in two sum problem we were asked to find the index of
         of elements , hence we cannot sort the array. so we used hashmap technique. here we need the elements only, so we 
         can use two pointer approach which is better.
**Also notice how we avoided duplicate triplets , this would not be possible if array is not sorted

Complexity
Time complexity:
O(n^2)

Space complexity:
O(n)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++){
            if(i > 0  && nums[i] == nums[i-1]){     /// to avoid duplicate triplets skip a target which is already computed
                continue;
            }
            int target = -nums[i];
            int left = i+1, right = n-1;
            while(left < right){
                if(nums[left] + nums[right] == target){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    ans.push_back(temp);
                    left++;
                    right--;
                    while(left < n && nums[left] == nums[left-1]){  // to avoid duplicates
                        left++;
                    }
                    while(right >= i+1 && nums[right] == nums[right+1]){    // to avoid duplicates
                        right--;
                    }
                }
                else if(nums[left] + nums[right] > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return ans;
    }
};


//using maps -- inefficient


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++){
            if(i > 0  && nums[i] == nums[i-1]){
                continue;
            }
            int target = -nums[i];
            unordered_map<int,int> mpp;
            for(int j= i+1; j<n; j++){
                if(mpp.find(target - nums[j]) != mpp.end()){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(mpp[target - nums[j]]);
                    temp.push_back(nums[j]);
                    ans.push_back(temp);
                    while(j+1 < n && nums[j+1] == nums[j]){
                        j++;
                    }
                }
                mpp[nums[j]] = nums[j];
            }
        }
        return ans;
    }
};