You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104


'Intuition'
-  we will only look for the increasing elements. If the array is sorted in descending order then, no answer is possible. 
-  if the array is sorted in non-descending order then the max profit is arr[0]-arr[n-1];

'Approach'
-  Look only when we have increasing order of element, if any such order is present then take the cummulative difference of
 those elements.

--since we can buy and sell any day, whenever there is profit possible between 2 consecutive days we add that to ans.
--we dont have to worry about buying on the least cost day and selling on the most cost day. when there is a price increase
  we sell the stock. the next day if price again increases, since we can buy again on the sold day, we have the stock 
  again for previous days price.



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for(int i=1; i<n; i++){
            if(prices[i] > prices[i-1]){
                profit += (prices[i] - prices[i-1]);
            }
        }
        return profit;
    }
};