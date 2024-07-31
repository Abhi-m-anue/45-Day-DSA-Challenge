Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
A subarray is a contiguous part of an array.


Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104



* The idea is to store the count of subarrays which have a particular remainder when divided with k
(if {sub-array 0 to i} and {sub-array 0 to j} has same remainder when divided by k ),then subarray [i,j] will be divisible by k


'Intuition'
-- Imagine you have an array of numbers, and you want to find subarrays (continuous segments of the array) whose sum is 
   perfectly divisible by a given number 𝑘. This problem can be thought of as a puzzle 🧩 where you need to find how often 
   certain patterns appear in the array, making the sum divisible by 𝑘.

-- The key insight 🔍 is to use the concept of remainders. By tracking the cumulative sum's remainder when divided by 𝑘,
   we can efficiently determine if a subarray's sum is divisible by 𝑘.

'Approach'

Cumulative Sum and Remainders :
-- As we traverse the array, we maintain a cumulative sum and compute its remainder when divided by 𝑘.
Frequency Map 📊:
-- Use a frequency map (array) to keep track of how often each remainder has occurred. This helps in determining how many times
   we have seen a particular pattern before.

Incremental Calculation :
-- For each element in the array, update the cumulative sum and compute the new remainder. If this remainder has been seen before
   it means there are subarrays that sum up to a multiple of 𝑘.

Count Subarrays 📈:
-- Each time we encounter a previously seen remainder, it indicates that the subarray between these points sums to a multiple 
   of 𝑘. We count these subarrays using our frequency map.

Handle Negative Numbers :
-- Adjust the remainder for negative numbers to ensure it stays within the valid range of 0 to 𝑘−1.


Complexity
Time complexity:
O(n)

Space complexity:
O(k)


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, ans = 0;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum % k == 0){
                ans++;
            }
            int rem = sum % k;
            if(rem < 0){
                rem = rem + k;
            }
            if(mpp.find(rem) != mpp.end()){
                ans += mpp[rem];
            }
            mpp[rem]++;
        }
        return ans;
    }
};