#include <vector>
#include <algorithm>
using namespace std;
/*
===============================================================================
 MAXIMUM SUBARRAY SUM (KADANE'S ALGORITHM)
===============================================================================

1. DRY RUN (Most Important)
   Example: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

   Initial: maxi = -2, sum = 0
   - num=-2: sum = 0 + (-2) = -2, maxi = max(-2, -2) = -2, sum < 0 so sum = 0
   - num=1:  sum = 0 + 1 = 1, maxi = max(-2, 1) = 1
   - num=-3: sum = 1 + (-3) = -2, maxi = max(1, -2) = 1, sum < 0 so sum = 0
   - num=4:  sum = 0 + 4 = 4, maxi = max(1, 4) = 4
   - num=-1: sum = 4 + (-1) = 3, maxi = max(4, 3) = 4
   - num=2:  sum = 3 + 2 = 5, maxi = max(4, 5) = 5
   - num=1:  sum = 5 + 1 = 6, maxi = max(5, 6) = 6
   - num=-5: sum = 6 + (-5) = 1, maxi = max(6, 1) = 6
   - num=4:  sum = 1 + 4 = 5, maxi = max(6, 5) = 6
   - Result: 6 (subarray [4, -1, 2, 1])

2. VISUALIZATION

   Array: [-2] [1] [-3] [4] [-1] [2] [1] [-5] [4]
            ↓
   Step 1:  sum=-2, maxi=-2, reset sum to 0 (negative)
            ↓
   Step 2:  sum=1, maxi=1
            ↓
   Step 3:  sum=-2, maxi=1, reset sum to 0 (negative)
            ↓
   Step 4:  sum=4, maxi=4
            ↓
   Step 5:  sum=3, maxi=4
            ↓
   Step 6:  sum=5, maxi=5
            ↓
   Step 7:  sum=6, maxi=6  ← Best so far!
            ↓
   Step 8:  sum=1, maxi=6
            ↓
   Step 9:  sum=5, maxi=6
            ↓
   Result:  6 (subarray: [4, -1, 2, 1])

3. WHY IT WORKS
   - sum tracks the best subarray ending at current position
   - If sum becomes negative, starting fresh gives better result
   - maxi tracks the best subarray seen so far anywhere
   - At each step, we either extend previous subarray or start new

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass through array
   - Space: O(1) - Only uses maxi and sum variables

5. KEY PATTERN
   Track running sum, reset to 0 when negative, keep maximum sum seen.
*/
int maxSubArray(vector<int>& nums) {
    int maxi = nums[0];
    int sum = 0;
    for (int num : nums) {
        sum += num;
        maxi = max(maxi, sum);
        if (sum < 0) sum = 0;
    }
    return maxi;
}
