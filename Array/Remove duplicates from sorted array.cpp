Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element 
appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in
nums initially. The remaining elements of nums are not important as well as the size of nums. Return k.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 
Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.



* simple two pointer 
* one pointer (i) keeps track of non-duplicate array index, while the other(j) traverses the array to find non-duplicate no.s
* we dont really need to create a count variable to store the no. of unique elements, just return i+1;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1,count = 1;
        // i indicates non-duplicate array index
        // j traverses the array and finds non-duplicate numbers and swap when found
        while(j<n){
            if(nums[i] == nums[j]){
                j++;                // move forward as the element is already part of ans
            }
            else if(nums[i] != nums[j]){
                count++;            // we found another non-duplicate number
                i++;                // move i one step furter before swapping
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return count;
        // return i+1;
    }
};
