#include <vector>
#include <algorithm>
using namespace std;

/*
===============================================================================
LEFT ROTATE ARRAY BY K PLACES
===============================================================================

1. DRY RUN (Most Important)
   Example: arr = [1, 2, 3, 4, 5], k = 2
   n = 5, k = k % n = 2

   Step 1: Reverse first k elements (indices 0 to 1)
   - Reverse [1, 2] → [2, 1]
   - Array: [2, 1, 3, 4, 5]

   Step 2: Reverse remaining elements (indices 2 to 4)
   - Reverse [3, 4, 5] → [5, 4, 3]
   - Array: [2, 1, 5, 4, 3]

   Step 3: Reverse entire array
   - Reverse [2, 1, 5, 4, 3] → [3, 4, 5, 1, 2]
   - Array: [3, 4, 5, 1, 2]

   Result: [3, 4, 5, 1, 2] (rotated left by 2)

2. VISUALIZATION

   Original: [1] [2] [3] [4] [5]
            ↓
   Step 1:  Reverse first 2
            [2] [1] [3] [4] [5]
            ↓
   Step 2:  Reverse last 3
            [2] [1] [5] [4] [3]
            ↓
   Step 3:  Reverse all
            [3] [4] [5] [1] [2]
            ↓
   Result:  Rotated left by 2

3. WHY IT WORKS
   - Left rotation by k means: first k elements go to end, rest shift left
   - Reverse first k: puts them in reverse order at front
   - Reverse rest: puts them in reverse order at back
   - Reverse all: reverses both parts, putting them in correct order
   - This achieves the rotation in O(n) time with O(1) space

4. TIME & SPACE COMPLEXITY
   - Time: O(n) - Three reverse operations, each O(n)
   - Space: O(1) - In-place reversal

5. KEY PATTERN
   Three reversals: first k, then rest, then entire array.
*/
void leftRotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}
