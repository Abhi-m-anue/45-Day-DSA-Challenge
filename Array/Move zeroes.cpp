Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?


'Two pointer'

* one pointer(i) two indicate the index of non-zero elements and the other(j) traverses the array 
* when j finds a non-zero element it assigns it to index i, and increments i. 
* if nums[j] is zero we ignore it.
* in the end we fill the array with zeros , from i to n-1

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = 0;
        while(j<n){
            if(nums[j] != 0){
                nums[i] = nums[j];              
            //  swap(nums[i] ,nums[j]);          WE CAN USE SWAP HERE SO THAT ZEROES AUTOMATICALLY COMES TO THE END
                i++;                            // WE CAN AVOID THE LAST LOOP BY DOING SO
            }
            j++;
        }
        while(i<n){
            nums[i] = 0;
            i++;
        }
    }
};