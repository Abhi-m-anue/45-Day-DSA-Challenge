You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the 
ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water 
the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104


* between two lines storable water is always limited by the shorter line. so we need to maximise the minimum among them
* maximum water can be stored btwn two lines which are farthest from each other( largest container width ). so we start from
  left=0 and right=n-1
* calculate possible water storage by eqn: max(maxWater,min(height[left],height[right])*(right-left))
* if height[right] is smaller among the two, we do right--, to look for a better height, as it is the limiting factor.
* otherwise do left++

- we do right-- 
  beacause, since right is the smaller among them the best container formable with right is already formed, any increase 
  in left is of no use as right becomes limiting factor.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), maxWater = 0;
        int left = 0, right = n-1;
        while(left < right){
            maxWater = max(maxWater,min(height[left],height[right])*(right-left));
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};