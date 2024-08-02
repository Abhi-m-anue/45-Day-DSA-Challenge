You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, 
where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.
Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.

It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.

 

Example 1:

Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
Output: 4
Explanation: The first two points satisfy the condition |xi - xj| <= 1 and if we calculate the equation
we get 3 + 0 + |1 - 2| = 4. Third and fourth points also satisfy the condition and give a value of 10 + -10 + |5 - 6| = 1.
No other pairs satisfy the condition, so we return the max of 4 and 1.
Example 2:

Input: points = [[0,0],[3,0],[9,2]], k = 3
Output: 3
Explanation: Only the first two points have an absolute difference of 3 or less in the x-values, and give the value
of 0 + 0 + |0 - 3| = 3.
 

Constraints:

2 <= points.length <= 105
points[i].length == 2
-108 <= xi, yi <= 108
0 <= k <= 2 * 108
xi < xj for all 1 <= i < j <= points.length
xi form a strictly increasing sequence.




* The question asks you to maximise (yi + yj + |xi - xj| ), for a sequece of x,y pairs where |xi - xj| <= k and i < j
* given that x is strictly increasing over the sequence.

- Suppose i < j, then we can translate yi + yj + |xi - xj| to (yi - xi) + (yj + xj).

explanation ::
{we can say for i < j => xi < xj, 
            so |xi - xj|  = -(xi - xj)
            then equation becomes (yi + yj + -(xi - xj) ) = (yi + yj -xi + xj) = (yi - xi) + (yj + xj)}

- we did this because we are now able to group xi and yi together and xj and yj together

- For a given point j, since (yj + xj) is fixed, we only need to maximize the (yi - xi) among the previously seen point_i.

- What data structure to use to efficiently find the biggest previously yi - xi for each point_j = (xj, yj)? MaxHeap!

- now for each point j take out the maximum yi - xi, stored in the maxHeap which satiesfies our condition and add it 
  to our current value. keep a variable to store the maximum of this computation from all iterations



class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = INT_MIN;
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
            int x = points[i][0], y = points[i][1];

            // if  xj - xi > k then we have to remove that from the queue as it can
			//no longer contribute to the answer which is given in the question itself 
            while(!pq.empty() && x - pq.top().second > k){
                pq.pop();
            }

            // now if the queue is not empty then the top of the queue is having maximum
			// value of  ( yi-xi) so we update our answer with  (top of the queue) + currvalue
            if(!pq.empty()){
                ans = max(ans, pq.top().first + x + y);
            }

            // inserting ( yi-xi ) and (xi) into the queue 
            pq.push({y - x, x});

        }

        return ans;
    }
};