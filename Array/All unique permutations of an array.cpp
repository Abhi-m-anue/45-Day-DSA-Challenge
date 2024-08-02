Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater
than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

Example 1:

Input: 
n = 3
arr[] = {1, 2, 1}
Output: 
1 1 2
1 2 1
2 1 1
Explanation:
These are the only possible unique permutations
for the given array.
Example 2:

Input: 
n = 2
arr[] = {4, 5}
Output: 
Only possible 2 unique permutations are
4 5
5 4

Expected Time Complexity:  O(n*n!)
Expected Auxilliary Space: O(n*n!)

Constraints:
1 ≤ n ≤ 9


Soln 

- It is a straightforward implementation solution.

Intuition:
- The idea is to generate all unique permutations of the given array arr in sorted order. 
- It employs a recursive approach to generate permutations, ensuring uniqueness by using a hash map (hash) to keep track 
  of already generated permutations.

Implementation:
- Initialize an empty current permutation (curr), an empty result vector (result), and an empty hash map (hash).
- Call the generator function to generate permutations.
- The generator function takes the current permutation (curr), the result vector (result), the current index (i), 
  the original array (A), and the hash map (hash) as parameters. Lets see what generate function does.
- If the current permutation size is equal to the array size.
    -it checks if the permutation has not been generated before using the hash map.
    -If unique, the curr vector is added to the result vector of vector, and the hash map is updated.
- Otherwise,
    -Run a loop j from i to A.size(),
    -Push A[j] into the curr vector and swap A[i] with A[j].
    -Call the recursion for i+1 index.
    -Pop the last element out of the vector and swap A[i] with A[j].
- sort the result vector of vector.
- Return result.


NOTE:: 
- the swap thing : each iteration we add an element to the permutaion vector. so we cant use that element for that recursive
  call, because its already part of permutation
- so we swap it with the element which is not part of current permutation which is arr[index] 


class Solution {
  public:
    // Function to generate unique permutations of the array
    void generator(vector<int> curr, vector<vector<int>> &result, int i, vector<int> A, map<vector<int>,int> &hash){
        if(curr.size()==A.size())
        {
            // Check if the current permutation has not been generated before
            if(hash.find(curr)==hash.end())
            {
                result.push_back(curr);
                hash[curr]=1;
            }
            return;
        }
        else
        {
            // Generate permutations by swapping elements at position i with elements starting from i
            for(int j=i; j<A.size(); j++)
            {
                curr.push_back(A[j]);
                swap(A[i],A[j]);
                
                // Recursive call to generate permutations with updated current permutation
                generator(curr,result,i+1,A,hash);
                
                curr.pop_back();
                swap(A[i],A[j]); // Swap back elements to restore original array
            }
        }
    }
    
    // Function to find unique permutations of the array
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        vector<int> curr;
        vector<vector<int>> result;
        map<vector<int>,int> hash;
        
        // Call the permutation generator function
        generator(curr,result,0,arr,hash);
        
        sort(result.begin(),result.end()); // Sort the result array in ascending order
        
        return result; // Return the unique permutations
    }
};