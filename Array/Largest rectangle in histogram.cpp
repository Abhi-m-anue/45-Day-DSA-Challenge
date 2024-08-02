Given an array of integers heights representing the histograms bar height where the width of each bar is 1,return the
area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4
 

* for every index we need to find the right boundary and left boundary. and the area enclosed btwn these two will give the 
  max area for that index 
* what are left/right boundaries ??
* for index i, left boundary is the first index to the left where height[left] < height[i]
* in that case all elements from left+1 to i will be >= height[i], so we can form a rectangle with them
* once we have left and right for all indexes 
  area[i] = (right[i] - left[i] - 1)* height[i]

Here is a shorter explanation :-
Main aim is to find the nearest smaller element to the left and the right as that would be the range of width we can 
extend for A[i]. The height is given to us. We than calculate the maximum area out of all of them.

* How to find left and right arrays???
* to find left[] ::
* we use a stack and keep pushing current elements to it.
* at each index, pop elements from stack till height[i] >= height[stack.top()]
* after this operation the element at top will be the left[i]. if the stack is empty, then there is no element to the left 
  of i, which is smaller than height[i]. so we can say left[i] = -1




class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i] = st.top();
            }
            else{
                left[i] = -1;
            }
            st.push(i);
        }
        // clear the stack
        while(!st.empty()){
            st.pop();
        }
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            else{
                right[i] = n;
            }
            st.push(i);
        }
        int area = 0;
        for(int i=0; i<n; i++){
            area = max(area, (right[i] - left[i] - 1)* heights[i]);
        }
        return area;
    }
};