Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. 
Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets 
among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a 
   student is minimum.

Example 1:

Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following M packets :{3, 4, 9, 7, 9}.
Example 2:

Input:
N = 7, M = 3
A = {7, 3, 2, 4, 9, 12, 56}
Output: 2
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing following M packets :{3, 2, 4}.


Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ Ai ≤ 109
1 ≤ M ≤ N


* we need to minimise the maximum difference between the 'M' elements taken from the array of size 'N'
* to minimise the difference btwn smallest and largest element in a block of 'M' elements, we need to pick elements which are
  as close as possible.
* so we sort the array first : because for an element say 'x' we need to pick m-1 more elements to make it of size 'M'.
  the best possible m-1 elements would be in the sorted array.
* in the sorted array we slide a window of size 'M' and each time update minDiff = min(minDiff,a[j]-a[i]);


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long i = 0,j = m-1, minDiff = INT_MAX;
        while(j < n){
            minDiff = min(minDiff,a[j]-a[i]);
            j++;
            i++;
        }
        return minDiff;
    
    }   
};

