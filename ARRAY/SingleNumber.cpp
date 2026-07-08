#include <vector>
#include <algorithm>
using namespace std;
/*
===============================================================================
SINGLE NUMBER (XOR)
===============================================================================

1. DRY RUN (Most Important)
   Example: nums = [4, 1, 2, 1, 2]
   XOR Property: A ^ A = 0, A ^ 0 = A

   Initial: xorr = 0
   - num=4: xorr = 0 ^ 4 = 4
   - num=1: xorr = 4 ^ 1 = 5
   - num=2: xorr = 5 ^ 2 = 7
   - num=1: xorr = 7 ^ 1 = 6  (1 cancels out previous 1)
   - num=2: xorr = 6 ^ 2 = 4  (2 cancels out previous 2)
   - Result: 4 (the single element)

2. VISUALIZATION

   Array: [4] [1] [2] [1] [2]
            ↓
   Step 1:  0 ^ 4 = 4
            ↓
   Step 2:  4 ^ 1 = 5
            ↓
   Step 3:  5 ^ 2 = 7
            ↓
   Step 4:  7 ^ 1 = 6  ← 1 cancels
            ↓
   Step 5:  6 ^ 2 = 4  ← 2 cancels
            ↓
   Result:  4 ✓ (single element)

3. WHY IT WORKS
   - XOR is commutative and associative: order doesn't matter
   - A ^ A = 0: Any number XORed with itself is 0
   - A ^ 0 = A: Any number XORed with 0 is itself
   - All pairs cancel out to 0, leaving only the single element

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Single pass through array
   - Space: O(1) - Only uses xorr variable

5. KEY PATTERN
   Use XOR to cancel out pairs; the remaining value is the single element.
*/
int singleNumber(vector<int>& nums) {
    int xorr = 0;
    for (int num : nums) {
        xorr ^= num;
    }
    return xorr;
}
