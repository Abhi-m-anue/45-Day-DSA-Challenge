Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1


'Merge sort modification'

How merge sort works:

void mergeSort(vector<int> &v){
        int n = v.size();
        if(n==1) return;
        int n1 = n/2, n2 = n - n/2;
        vector<int> a(n1), b(n2);
        // copy paste
        for(int i=0; i<n1; i++) a[i] = v[i];
        for(int i=0; i<n2; i++) b[i] = v[i+n1];
        // recursion
        mergeSort(a);
        mergeSort(b);
        // merge
        merge(a,b,v);
        a.clear(); b.clear();
    }
- The merge sort function takes an array and keeps dividing it into two halves until a singleton array or a single element
  is achieved and then the merge function merges these two sorted arrays {an array with an single element is always sorted} 
  into a resultant sorted array.

- while this whole merge sort thing is getting done we can very efficiently count our reverse pairs right before merging
 the two arrays using the knowledge that the arrays are now sorted.

mergeSort(a);
mergeSort(b);
// count reverse pairs
c += revPairs(a,b);
 // merge
merge(a,b,v);

"MAIN PART"

- Consider two arrays A and B which are a part of some array from any testcase and try to make the reverse pairs taking one 
  element from each array at a time.

Efficieny Part- 
- if lets say the Kth element from array A is greater than twice of say the Nth element of array B

long long int bruh = b[j];
if(a[i]>2*bruh){
    count += a.size()-i;
    j++;
}
- in this case the Kth element and every element after it would form a reverse pair with the Nth element of array B since 
  the element are in sorted order and in this case you do not need to check every element after the Kth element individually 
  and you can just count them altogether saving your number of operations and reducing your time complexity to NlogN from the
  initial N^2

- else in case the Kth element from array A is not greater than twice of Nth element of array B you can just iterate over
  array A until you find an element that satisfies the condition.


Complexity
Time complexity: O(nlogn)
Space complexity: O(n)

class Solution {
    int count = 0;
    void countRevPairs(vector<int> &a, vector<int> &b){
        int i = 0, j = 0;
        while(i<a.size() && j<b.size()){
            long long int temp = b[j];
            if(a[i] > temp*2){
                count += a.size() - i;
                j++;
            }
            else{
                i++;
            }
        }
    }
    void merge(vector<int> &a, vector<int> &b, vector<int> &vec){
        int i = 0, j =0, k =0;
        while(i<a.size() && j<b.size()){
            if(a[i] <= b[j]){
                vec[k++] = a[i++];
            }
            else{
                vec[k++] = b[j++];
            }
        }
        while(i<a.size()){
            vec[k++] = a[i++];
        }
        while(j<b.size()){
            vec[k++] = b[j++];
        }
        
    }
    void mergeSort(vector<int>& nums){
        if(nums.size() == 1){
            return;
        }
        int n1 = nums.size()/2;
        int n2 = nums.size()-n1;
        vector<int> a(n1);
        vector<int> b(n2);
        for(int i = 0; i<n1; i++) a[i] = nums[i];
        for(int j = 0; j<n2; j++) b[j] = nums[j+n1];
        mergeSort(a);
        mergeSort(b);

        countRevPairs(a,b);
        
        merge(a,b,nums);
        a.clear();
        b.clear();
    }
public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums);
        return count;
    }
};