Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107

"basic idea"

* Basic idea is to store a prefix array and maintain a map.
* each time we update prefix array by adding current element, and map by incrementing frequency of current prefixSum{prefix[i]}
* if prefix[i] - k is found in the map we can say that , we had a sub-array whose prefix sum was prefix[j] = prefix[i] - k
* Then the sub-array between these two indexes {i,j} will have a sum of elements  = prefix[i] - prefix[j]
                                                                                  = prefix[i] - prefix[i] - k
                                                                                  = k
* Therefore we can increment the ans by the count of such prefix[j] s


"Better understanding"

So, suppose we have an array as arr[]: [1,2,3,4,5] and k = 9

so, our answer will be '2' i.e (2 + 3 + 4 and 4 + 5)
so if we store our prefix sum array then it should looks like:
index :   0, 1, 2, 3,  4
  arr[]: [1, 2, 3, 4,  5]
prefix[]:[1, 3, 6, 10, 15]
          ↑         ↑

How, we will find our subarray (2 + 3 + 4) using prefix sum, see-

1) if we see our prefix sum at index 3 then it is 10 and also prefix sum at index 0 is 1
so, we can say that from index 0 to 3 our prefix sum increases from 1 to 10, right,

2) So on putting a question, HOW MUCH ? means how much our sum increase from index 0 to index 3
then, we simply say, we find the difference between these two sums i.e (10 - 1) is the sum that increases from index 0 to 3.

3) If (10 - 1) sum increases from index 0 to 3, then we can say that, ok, this difference, should be the sum of elements 
  greater than index 0, and upto index 3, i.e from index 1 to index 3,right.

4) Now, if we will see then we find out (10 - 1) is nothing but our 'k' that is 9.

5) So, we find out, that a subarray may also exist if this particular condition satisified, i.e
    (prefix[i] - k) should exist in our map, 
	
	How? see,
	
	If prefix[i] - prefix[j] = k where i > j (i, j any index, in our case they are i = 3, j = 0)
	prefix[i] - k = prefix[j] na, (simple maths)
	
	i.e if we are able to find (prefix[i] - k) is exist in our map, i.e prefix[j]
	so, we can say that from index j + 1 to i, the sum of the elements is k, right na,
	hence it proves that their exist an subarray from index j + 1 to i whose sum is k.
	
Now, for subarray (4 + 5) we again find this valid see -

index :   0, 1, 2, 3,  4
  arr[]: [1, 2, 3, 4,  5]
prefix[]:[1, 3, 6, 10, 15]
                ↑       ↑
				
1) if we see our prefix sum at index 4 then it is 15 and also prefix sum at index 2 is 6
so, we can say that from index 2 to 4 our prefix sum increases from 6 to 15, right,

2) So on putting a question, HOW MUCH ? means how much our sum increase from index 2 to index 4
then, we simply say, we find the difference between these two sums i.e (15 - 6) is the sum that increases from index 2 to 4.

3) If (15 - 6) sum increases from index 2 to 4, then we can say that, ok, this difference, should be the sum of elements greater than index 2, and upto index 4, i.e from index 3 to index 4,right.

4) Now, if we will see then we find out (15 - 6) is nothing but our 'k' that is 9.

5) So, we find out, that a subarray may also exist if this particular condition satisified, i.e
    (prefix[i] - k) should exist in our map, right na,
	
	How? see,
	
	If prefix[i] - prefix[j] = k where i > j (i, j any index, in our case they are i = 4, j = 2)
	prefix[i] - k = prefix[j] na, (simple maths)
	
	i.e if we are able to find (prefix[i] - k) is exist in our map, i.e prefix[j]
	so, we can say that from index j + 1 to i, the sum of the elements is k, right na,
	hence it proves that their exist an subarray from index j + 1 to i whose sum is k.
	
	I hope u got the reason now, why we will do (prefix[i] - k) in our code.


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixSum[n];
        prefixSum[0] = nums[0];
        int ans = 0;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            if(i > 0){
                prefixSum[i] = prefixSum[i-1] + nums[i];
            }
            if(prefixSum[i] == k){
                ans++;
            }
            if(mpp.find(prefixSum[i] - k) != mpp.end()){
                ans += mpp[prefixSum[i] - k];
            }
            mpp[prefixSum[i]]++;
        }
        return ans;
    }
};