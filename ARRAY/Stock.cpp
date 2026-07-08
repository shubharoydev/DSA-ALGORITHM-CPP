#include <vector>
#include <algorithm>
using namespace std;
/*
===============================================================================
STOCK BUY AND SELL
===============================================================================

1. DRY RUN (Most Important)
   Example: prices = [7, 1, 5, 3, 6, 4]

   Initial: minPrice = 7, maxProfit = 0
   - i=1: price=1, cost=1-7=-6, maxProfit=max(0,-6)=0, minPrice=min(7,1)=1
   - i=2: price=5, cost=5-1=4, maxProfit=max(0,4)=4, minPrice=min(1,5)=1
   - i=3: price=3, cost=3-1=2, maxProfit=max(4,2)=4, minPrice=min(1,3)=1
   - i=4: price=6, cost=6-1=5, maxProfit=max(4,5)=5, minPrice=min(1,6)=1
   - i=5: price=4, cost=4-1=3, maxProfit=max(5,3)=5, minPrice=min(1,4)=1
   - Result: 5 (buy at 1, sell at 6)

2. VISUALIZATION

   Prices: [7] [1] [5] [3] [6] [4]
            ↓
   Day 0:   minPrice=7, maxProfit=0
            ↓
   Day 1:   minPrice=1, cost=-6, maxProfit=0
            ↓
   Day 2:   minPrice=1, cost=4, maxProfit=4  ← Better!
            ↓
   Day 3:   minPrice=1, cost=2, maxProfit=4
            ↓
   Day 4:   minPrice=1, cost=5, maxProfit=5  ← Best!
            ↓
   Day 5:   minPrice=1, cost=3, maxProfit=5
            ↓
   Result:  maxProfit=5 (buy day 1, sell day 4)

3. WHY IT WORKS
   - minPrice tracks the lowest price seen so far (best buy point)
   - At each day, we calculate profit if we sold today (price - minPrice)
   - maxProfit keeps the best profit seen so far
   - We update minPrice when we find a lower price (better future buy)

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass through prices
   - Space: O(1) - Only uses minPrice and maxProfit

5. KEY PATTERN
   Track minimum price seen, calculate profit at each step, keep maximum profit.
*/
int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
        int cost = prices[i] - minPrice;
        maxProfit = max(maxProfit, cost);
        minPrice = min(minPrice, prices[i]);
    }
    return maxProfit;
}