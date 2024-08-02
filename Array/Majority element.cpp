Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always 
exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109


- we can solve this easily by sorting and returning the middle element or , by using hashmap
- but we need to solve it using linear time and constant space.

'Moore Voting alogorithm'

Intuition:
- The intuition behind the Moore's Voting Algorithm is based on the fact that if there is a majority element in an array, 
  it will always remain in the lead, even after encountering other elements.

Explanation:
Algorithm:

- Initialize two variables: count and candidate. Set count to 0 and candidate to an arbitrary value.
- Iterate through the array nums:
a. If count is 0, assign the current element as the new candidate and increment count by 1.
b. If the current element is the same as the candidate, increment count by 1.
c. If the current element is different from the candidate, decrement count by 1.
- After the iteration, the candidate variable will hold the majority element.

Explanation:

- The algorithm starts by assuming the first element as the majority candidate and sets the count to 1.
- As it iterates through the array, it compares each element with the candidate:
a. If the current element matches the candidate, it suggests that it reinforces the majority element because it appears again
   Therefore, the count is incremented by 1.
b. If the current element is different from the candidate, it suggests that there might be an equal number of occurrences 
   of the majority element and other elements. Therefore, the count is decremented by 1.
- Note that decrementing the count doesnt change the fact that the majority element occurs more than n/2 times.
- If the count becomes 0, it means that the current candidate is no longer a potential majority element. In this case, a 
  new candidate is chosen from the remaining elements.
- The algorithm continues this process until it has traversed the entire array.
- The final value of the candidate variable will hold the majority element.

Explanation of Correctness:
- The algorithm works on the basis of the assumption that the majority element occurs more than n/2 times in the array. 
- This assumption guarantees that even if the count is reset to 0 by other elements, the majority element will eventually
  regain the lead.



NOTE:: 
- Think like this, the maximum vote any element other than majority element can get is (n/2 - 1), while majority element will 
  have n/2 + 1 votes


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int candidate ;
        for(int i=0; i<n; i++){
            if(count == 0){
                candidate = nums[i];
            }
            if(nums[i] == candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};