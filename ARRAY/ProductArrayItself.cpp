#include <vector>
#include <algorithm>
using namespace std;
/*
===============================================================================
PRODUCT OF ARRAY EXCEPT ITSELF
===============================================================================

1. DRY RUN (Most Important)
   Example: nums = [1, 2, 3, 4]

   Prefix Pass (left to right):
   Initial: res = [1, 1, 1, 1], prefix = 1
   - i=0: res[0] = prefix = 1, prefix *= nums[0] = 1*1 = 1
   - i=1: res[1] = prefix = 1, prefix *= nums[1] = 1*2 = 2
   - i=2: res[2] = prefix = 2, prefix *= nums[2] = 2*3 = 6
   - i=3: res[3] = prefix = 6, prefix *= nums[3] = 6*4 = 24
   - After prefix: res = [1, 1, 2, 6]

   Suffix Pass (right to left):
   Initial: suffix = 1
   - i=3: res[3] *= suffix = 6*1 = 6, suffix *= nums[3] = 1*4 = 4
   - i=2: res[2] *= suffix = 2*4 = 8, suffix *= nums[2] = 4*3 = 12
   - i=1: res[1] *= suffix = 1*12 = 12, suffix *= nums[1] = 12*2 = 24
   - i=0: res[0] *= suffix = 1*24 = 24, suffix *= nums[0] = 24*1 = 24
   - Final: res = [24, 12, 8, 6]

2. VISUALIZATION

   Input:   [1] [2] [3] [4]

   Prefix:  [1] [1] [2] [6]  ← Product of elements to the left
            ↓   ↓   ↓   ↓
            1   1   2   6

   Suffix:  Multiply by product of elements to the right
            ↓   ↓   ↓   ↓
   [24] [12] [8] [6]
   ×24  ×12  ×4   ×1

   Result:  [24] [12] [8] [6]
   - 24 = 2×3×4
   - 12 = 1×3×4
   - 8  = 1×2×4
   - 6  = 1×2×3

3. WHY IT WORKS
   - Prefix pass: res[i] = product of all elements before i
   - Suffix pass: multiply res[i] by product of all elements after i
   - Result: res[i] = (product before i) × (product after i)
   - This equals product of all elements except nums[i]

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Two passes through array
   - Space: O(1) extra (output array doesn't count)

5. KEY PATTERN
   Two passes: left-to-right for prefix products, right-to-left for suffix products.
*/
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 1);
    
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        res[i] = prefix;
        prefix *= nums[i];
    }
    
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= suffix;
        suffix *= nums[i];
    }
    return res;
}
