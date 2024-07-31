Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.


Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.


---'Binary search'---

* we do binary search along the array indices, not values as values are not sorted, and cannot be sorted because modificaion
  of original array is not allowed

* We perform binary search on the range [1, n], and for each mid value, we count the number of elements in the array that
 are less than or equal to the mid value.
* If the count is greater than mid, then the duplicate lies in the left half of the range; otherwise, it lies in the
 right half.
* If there's no duplicate, in a sorted array, we would expect nums[i] to be equal to i + 1 for each i. However, with a
 duplicate, there will be more than mid + 1 numbers less than or equal to mid.
* We continue narrowing down the range until we find the duplicate number.

'Reason':
* if there is no repetetion of elements, for an index mid, there will be exactly mid number of elements in the array <= mid 
* if the count is > mid ,this means a number was repeated in the range [left,mid] so we do right = mid 

'Dry run'
If anyone is having a hard time understanding the binary search method, left and right represents the range 1 to N.

input = {3,1,4,2,2,2}

-- range 1-5 , mid = 3 (in range itself), count = 5 which means (1 , 2 , 3 , ? , ?), count should be 3 because there are only 3 
numbers that are less than equal to 3(mid) so 1,2 or 3 could be the duplicate, so we shorten range to 1-3

-- range 1-3, mid = 2, count = 4 (1,2,?,?), shorten range to 1-2, same reason as the first iteration

-- range 1-2, mid = 1, count = 1 (1), range shorten to 2 which is the duplicate

Complexity
Time complexity: O(NlogN)
Space complexity: O(1)



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n-1; // left and right represents values in the range [1,n], not array indexes
        while(left < right){
            int mid = left + (right - left)/2;
            int i = 0,count = 0;
            while(i<n){
                if(nums[i] <= mid){
                    count++;
                }
                i++;
            }

            if(count > mid){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};


'Fast and slow pointers'

* we can solve this problem similar to find and remove cycle in linked list 
* to understand why it works ,see the working on Geek for geeks

'steps'
-- The key intuition behind this method is that if there's a cycle in the linked list, the fast and slow pointers will 
   eventually meet.
-- We treat the array as a linked list, where the index represents the node and the value at that index represents the next node.
-- Using the fast-slow pointers technique, we traverse the linked list.
-- The slow pointer moves one step at a time while the fast pointer moves two steps at a time.
-- If there's a cycle in the linked list (indicating a duplicate number), the fast and slow pointers will eventually meet.
-- After identifying the meeting point, we reset the slow pointer to the start and move both pointers at the same pace until 
   they meet again. The meeting point will be the duplicate number.

Complexity
Time complexity: O(N)
Space complexity: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);
        slow = 0;
        do{
            slow = nums[slow];
            fast = nums[fast];
        }
        while(slow != fast);
        return slow;
    }
};