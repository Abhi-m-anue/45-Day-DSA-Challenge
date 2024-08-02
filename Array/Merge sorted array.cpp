You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the
number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate 
this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n 
elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 



* we can use two pointers poiniting at nums1 and nums2 to compare the elements one by one and merge them.
* the complexity is that we are merging in to nums1 array. so if we do normal merging the values of nums1 will get over written
  when nums2[j] < nums1[i]
* to solve this we can merge from the end. ie. keep i = m-1, j=n-1 . Then compare them and add the larger value to last index
  of nums1.
* Since last n values of nums1 are initialised to 0, even if entire nums2 is larger than nums1, original values of
  nums1 will not be destroyed.  

Intuition
- We are given two sorted arrays nums1 and nums2 of sizes m and n, respectively.
- We need to merge these two arrays into a single sorted array, and the result should be stored inside nums1.
- Since nums1 is of size m+n, we can use this extra space to store the merged array. We can iterate through the arrays
  from the end and place the larger element in the end of nums1.

Approach : Two Pointer
- We can start with two pointers i and j, initialized to m-1 and n-1, respectively.
- We will also have another pointer k initialized to m+n-1, which will be used to keep track of the position in nums1
  where we will be placing the larger element.
- Then we can start iterating from the end of the arrays i and j, and compare the elements at these positions.
- We will place the larger element in nums1 at position k, and decrement the corresponding pointer i or j accordingly. 
- We will continue doing this until we have iterated through all the elements in nums2. 
- If there are still elements left in nums1, we don't need to do anything because they are already in their correct place




class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        int index = m+n-1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[index] = nums1[i];
                i--;
            }
            else{
                nums1[index] = nums2[j];
                j--;
            }
            index--;
        }

        // while(i >= 0){               if there are elements left in nums1, it will be already in its position
        //     nums1[index] = nums1[i];
        //     i--;
        //     index--;
        // }
        while(j >= 0){
            nums1[index] = nums2[j];
            j--;
            index--;
        }
    }
};