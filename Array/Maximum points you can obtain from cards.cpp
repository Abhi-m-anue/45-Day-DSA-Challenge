There are several cards arranged in a row, and each card has an associated number of points. The points are given in the 
integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 
Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize 
your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 

Constraints:

1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length




Intuition
The idea here is pretty tricky to guess...

What we do is we initialize a window of size k...
- Now, since we can select either from the start or from the end, we only have access to either the first k items or
  last k items,and hence we are trying to limit our access using this window...
- So, we include all the elements from start in our window, till its full..
- The sum of elements at each instance in our window will be kept track of using another variable that will store our result.
- Now, we remove the last element from our window, and add the last unvisited element from the back end of our array
- Similarly we keep on removing 1 element from our window and start adding the last unvisited element of our cardPoints array.
- We keep doing this until we reach the start of our array, in this way we have covered all our possible picks...


Lets perform a dry run of the provided code with the input cardPoints = [1,2,3,4,5,6,1] and k = 3 

Initialization:

n = 7 (length of cardPoints)
sum = 1 + 2 + 3 = 6 (sum of first k = 3 cards)
ans = 6 (initialize ans with sum)
Sliding Window Technique:

Start with i = 2 (last index of the first k cards) and j = 6 (last index of the array)
Iteratively update sum by sliding the window:
sum = sum - arr[2] + arr[6] = 6 - 3 + 1 = 4 (update sum)
ans = max(6, 4) = 6(no update to ans since 6 is greater than 4)

Move i and j inward:
i = 1, j = 5
sum = sum - arr[1] + arr[5] = 4 - 2 + 6 = 8 (update sum)
ans = max(6, 8) = 8 (update ans to 8)

Move i and j inward again:
i = 0, j = 4
sum = sum - arr[0] + arr[4] = 8 - 1 + 5 = 12 (update sum)
ans = max(8, 12) = 12 (update ans to 12)
Loop ends (i = -1, j = 3), and the maximum score (ans = 12) is returned.



class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(),score = 0;
        int i = 0;
        while(i < k){
            score += cardPoints[i];
            i++;
        }
        i--;              // The while loop exited with i = k, but we need i = k-1
        int j = n-1;
        int curr = score;
        while(i >= 0){
            curr -= cardPoints[i];
            curr += cardPoints[j];
            score = max(score,curr);
            i--;
            j--;
        }
        return score;
    }
};